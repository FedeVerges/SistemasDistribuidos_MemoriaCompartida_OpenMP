#include <stdio.h>
#include <omp.h>
int main(int argc, char **argv)
{
    omp_set_num_threads(2);
    int vector_size = 5;
    int vector_a [vector_size];
    int vector_b [vector_size];
    int index;
    int vector_resultado[5];

// Inicialize vector

    for (int i = 0; i < vector_size; i++)
    {
        vector_a[i]= i+1;
        vector_b[i]= i+1;
    }

#pragma omp parallel private(index)
    {
        #pragma omp for
        for(index = 0; index<vector_size; index++){
            vector_resultado[index] = vector_a[index] + vector_b[index];
    }

}
    printf("Resultado : ");
    for (int i = 0; i < vector_size; i++)
    {
        printf(" %d ", vector_resultado[i]);
    }

    return (0);
}