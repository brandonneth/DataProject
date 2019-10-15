

#define NUMELEMENTS 1000
#include <stdlib.h>
#include <stdio.h>
#include <omp.h>
int main()
{ 
    double * A = (double*) malloc(sizeof(double) * NUMELEMENTS);
    double * B = (double*) malloc(sizeof(double) * NUMELEMENTS);
    double * C = (double*) malloc(sizeof(double) * NUMELEMENTS);
    double * D = (double*) malloc(sizeof(double) * NUMELEMENTS);
    for(int i = 0; i < NUMELEMENTS; i++)
    {
        A[i] = i;
        B[i] = i * 3;
    }
	
    printf("num devices: %d\n", omp_get_num_devices());
    
    #pragma omp target data map(tofrom: A[0:NUMELEMENTS])
    {
    #pragma omp target
    #pragma omp parallel for
    for(int i = 0; i < NUMELEMENTS; i++)
        A[i] = omp_is_initial_device();
    }
    if(A[1] == 0)
    {
        printf("successfully offloaded to target\n");
    }
    else
    {
        printf("failed to offload to target\n");
    }
    
    for(int i = 0; i < NUMELEMENTS; i++)
    {
        A[i] = omp_is_initial_device();
    }
    if(A[1] == 0)
    {
        printf("loop2: successfully offloaded to target\n");
    }
    else
    {
        printf("loop2: failed to offload to target\n");
    }

    
    
    
    
}

