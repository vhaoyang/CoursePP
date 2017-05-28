/* File:     mp-atomic.c
 *
 * Purpose:  A parallel program that uses OpenMP atomic
 *
 * Compile:  gcc -g -Wall -fopenmp mp-atomic.c -o mp-atomic 
 * Run:      ./mp-atomic 
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
   int sumx = 1;
   int sumy = 2;

#  pragma omp parallel num_threads(4) shared(sumx,sumy) 
   {
#  pragma omp atomic
	  sumx += omp_get_thread_num();
#  pragma omp atomic
	  sumy += omp_get_thread_num();
   }
   printf("sumx = %d, sumy = %d\n",sumx,sumy);

   return 0; 
} 

