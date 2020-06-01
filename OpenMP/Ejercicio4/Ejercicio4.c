#include <stdio.h>
#include <omp.h>
int main(int argc, char **argv)
{
    int n, tid;
    omp_set_num_threads(5);
    int b [50];
    int a[50];
    for (int i = 0; i < 50; i++)
    {
        b[i]= i;
    }
    b[6]= 50;
    
#pragma omp parallel private(n)
    {
#pragma omp for
        for (int n = 0; n < 10; n++)
        {
            a[n] = (2*n);
            printf("a: %d \n", a[n]);
            printf("b: %d \n", b[n]);
            if (a[n] < b[n]) {
                printf("out");
                n=10;
                }
        }
    }
    return (0);
}