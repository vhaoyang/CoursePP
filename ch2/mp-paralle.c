/* File:     mp-paralle.c
 *
 * Purpose:  A parallel program that uses OpenMP paralle
 *
 * Compile:  gcc -g -Wall -fopenmp mp-paralle.c -o mp-paralle 
 * Run:      ./mp-paralle <number of threads>
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
   int id = omp_get_thread_num();
   int count = 0;
   for (int i = 0; i< id; i++)
	   count--;

   printf("Thread %d & Number %d\n", id,count);
}
   return 0; 
} 

