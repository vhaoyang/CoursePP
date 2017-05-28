/* File:     mp-hello-ifdef.c
 
 * Purpose:  A parallel program that uses OpenMP
 *
 * Compile:  gcc -g -Wall -fopenmp mp-hello-ifdef.c -o mp-hello-ifdef 
 * Run:      ./mp-hello-ifdef <number of threads>
 * 
 * Input:    
 * Output:   
 *
 */
#include <stdio.h>
#include <stdlib.h>
#ifdef _OPENMP
#  include <omp.h>  
#endif 

/*--------------------------------------------------------------------*/
/* main */
/*--------------------------------------------------------------------*/
int main(int argc, char* argv[]) {
   int num_t = strtol(argv[1], NULL, 10); 

#  pragma omp parallel num_threads(num_t) 
{
#  ifdef _OPENMP	
   int rank_t = omp_get_thread_num();
#  else
   int rank_t = 0;
#  endif    
   printf("Thread %d says hello to you!\n", rank_t);
}

   return 0; 
} 

