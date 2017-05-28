/* File:     mp-hello.c
 *
 * Purpose:  A parallel program that uses OpenMP
 *
 * Compile:  gcc -g -Wall -fopenmp mp-hello.c -o mp-hello 
 * Run:      ./mp-hello <number of threads>
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

#  pragma omp parallel num_threads(num_t) 
{
   int rank_t = omp_get_thread_num();
   printf("Thread %d says hello to you!\n", rank_t);
}

   return 0; 
} 

