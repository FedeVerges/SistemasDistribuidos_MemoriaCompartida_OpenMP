#include <omp.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <math.h>
#include <time.h>

#define N 1000000
#define LAPS 50

// Execute with " gcc -o ejercicio8Paralelo -lm -fopenmp Ejercicio8.c ".

double multiplication(int *elements, int n)
{
    double temp = 1;
    for (int i = 0; i < n; i++)
    {
        temp = temp * elements[i];
    }

    return temp;
}

int minimum(int *elements, int n)
{
    int acum = elements[0];
    for (int i = 1; i < n; i++)
    {
        if (elements[i] < acum)
        {
            acum = elements[i];
        }
    }
    return acum;
}

int maximum(int *elements, int n)
{
    int acum = elements[0];
    for (int i = 1; i < n; i++)
    {
        if (elements[i] > acum)
        {
            acum = elements[i];
        }
    }
    return acum;
}

int standar_desviation(int *elements, int n)
{
    int num = 0, sum = 0, average = 0, sigma = 0, standar_desviation = 0;

    for (int i = 0; i < n; i++)
    {
        sum += elements[i];
    }

    average = sum / n;

    for (int i = 0; i < n; i++)
    {
        sigma += ((elements[i] - average) * (elements[i] - average));
    }

    standar_desviation = sqrt(sigma / (n - 1));

    return standar_desviation;
}

double Secuencial(int *elements, int n, int laps)
{
    double start, finish;
    double time_speedup = 0;

    for (int index = 0; index < laps; index++)
    {
        start = omp_get_wtime();

        int min = 0, max = 0, sd = 0;
        double mult = 0;
        mult = multiplication(elements,n);
        min = minimum(elements,n);
        max = maximum(elements,n);
        sd = standar_desviation(elements,n);

        finish = omp_get_wtime();
        time_speedup += (double)(finish - start);
    }

    return time_speedup / laps;
}

double Paralell(int *elements, int n, int laps)
{
    double start, finish;
    double time_speedup = 0;
    int num_threads = omp_get_num_threads; // obtain the num. of threads.
    if (num_threads >= 4)
    {
        num_threads = 4;
        omp_set_num_threads(num_threads);
    }

    for (int i = 0; i < laps; i++)
    {
        int min = 0, max = 0, sd = 0;
        double mult = 0;
        int num_process;

        start = omp_get_wtime();

#pragma omp parallel shared(elements, mult, min, max, sd) private(num_process)
        {

            // num_process = omp_get_thread_num();
#pragma omp sections
            {
#pragma omp section
                {
                    // printf("I'm thread: %d and do multiplication \n", num_process);
                    mult = multiplication(elements,n);
                }
#pragma omp section
                {
                    // printf("I'm thread: %d and do minimum \n", num_process);
                    min = minimum(elements,n);
                }
#pragma omp section
                {
                    // printf("I'm thread: %d and do maximum \n", num_process);
                    max = maximum(elements,n);
                }
#pragma omp section
                {
                    //printf("I'm thread: %d and do standar_desviation \n", num_process);
                    sd = standar_desviation(elements,n);
                }

            } // End Sections
        }
        finish = omp_get_wtime();
        

        time_speedup += (double)((finish - start));
    }
    return time_speedup / laps;

}

// ** Main Program ** //

int main()
{

    // Elements to process.
    int *elements = (int *)calloc(N, sizeof(int));

    double speedup_final = 0;

    // Inicialice the vector.
    for (int i = 0; i < N; i++)
    {
        elements[i] = i + 1;
    }

    // Statics
    double time_Secuencial = 0, time_Paralell = 0;

    time_Secuencial = Secuencial(elements, N, LAPS);
    time_Paralell = Paralell(elements, N, LAPS);

    speedup_final = time_Secuencial / time_Paralell;

    printf("Tiempo Promedio Algoritmo Secuencial = %f \n", time_Secuencial);
    printf("Tiempo Promedio Algoritmo Paralelo = %f \n", time_Paralell);

    printf("Tiempo Total Speeup = %f \n", speedup_final);

    //free(elements);
    // freeArray(*elements);
}
