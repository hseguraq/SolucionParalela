// PruebaOMP.cpp : Defines the entry point for the application.
//
#include "pch.h"
#include <iostream>
#include <omp.h>
#include <cstdlib>  // For rand() and srand()
#include <ctime>    // For time()

#define N 1000
#define chunk 100
#define mostrar 15

void imprimeArreglo(float* d);

int main()
{
    std::cout << "Sumando Arreglos en Paralelo!\n";
    float a[N], b[N], c[N];
    int i;

    srand(time(0));

    for (i = 0; i < N; i++)
    {
        a[i] = rand() % 100 + 1;
        b[i] = rand() % 100 + 1;
    }

    int pedazos = chunk;

#pragma omp parallel for \
    shared(a, b, c, pedazos) private(i) \
    schedule(static, pedazos)

    for (i = 0; i < N; i++)
        c[i] = a[i] + b[i];

    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo a: " << std::endl;
    imprimeArreglo(a);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo b: " << std::endl;
    imprimeArreglo(b);
    std::cout << "Imprimiendo los primeros " << mostrar << " valores del arreglo c: " << std::endl;
    imprimeArreglo(c);

    return 0;
}

void imprimeArreglo(float* d)
{
    for (int x = 0; x < mostrar; x++)
        std::cout << d[x] << " - ";
    std::cout << std::endl;
}
