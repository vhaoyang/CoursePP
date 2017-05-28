/* File:     mp-lock.c
 *
 * Purpose:  A parallel program that uses OpenMP lock
 *
 * Compile:  gcc -g -Wall -fopenmp mp-lock.c -o mp-lock 
 * Run:      ./mp-lock 
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

   omp_lock_t lock;
   omp_init_lock(&lock);
#  pragma omp parallel num_threads(4) shared(sumx,sumy) 
   {
      omp_set_lock(&lock);
	  sumx += omp_get_thread_num();
	  sumy += omp_get_thread_num();
      omp_unset_lock(&lock);
   }
   printf("sumx = %d, sumy = %d\n",sumx,sumy);
   omp_destroy_lock(&lock);

   return 0; 
} 

