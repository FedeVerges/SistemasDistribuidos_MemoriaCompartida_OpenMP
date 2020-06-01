#include <stdio.h>
#include <omp.h>
 
 // Correr con "gcc -o ejercicio1 -fopenmp Ejercicio1.c".

int main(){
    int nthreads, tid;
    #pragma omp parallel private(tid) 
    {
        tid = omp_get_thread_num();
        printf("Hola desde el thread: %d\n", tid);

        if(tid ==0){
            nthreads = omp_get_num_threads();
            printf("Soy el thread master y hay %d threads ejecutando ", nthreads);
        }

    }
    return 0;
}
