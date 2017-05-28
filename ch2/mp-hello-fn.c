/* File:     mp-hello-fn.c
 *
 * Purpose:  A parallel program that uses OpenMP function
 *
 * Compile:  gcc -g -Wall -fopenmp mp-hello-fn.c -o mp-hello-fn 
 * Run:      ./mp-hello-fn <number of threads>
 * 
 * Input:    
 * Output:   
 *
 */
#include <stdio.h>
#include <stdlib.h>
#include <omp.h>   

/*--------------------------------------------------------------------*/
/* main */
/*--------------------------------------------------------------------*/
int main(int argc, char* argv[]) {
   int num_t = strtol(argv[1], NULL, 10); 
   
   printf("proc count %d \n",omp_get_num_procs());
   printf("thread count %d \n",omp_get_num_threads());
#  pragma omp parallel num_threads(num_t) 
{
   printf("Thread %d says hello to you!\n", omp_get_thread_num());
   printf("thread count %d \n",omp_get_num_threads());
}
   printf("thread count %d \n",omp_get_num_threads());
   return 0; 
} 

