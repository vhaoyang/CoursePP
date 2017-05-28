/* File:     mp-acc4.c
 *
 * Purpose:  A parallel program that uses OpenMP parallel for
 *
 * Compile:  gcc -g -Wall -fopenmp mp-acc4.c -o mp-acc4 
 * Run:      ./mp-acc4 <max number of accumulation> <number of threads>
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
   int max_num = strtol(argv[1], NULL, 10);
   int num_t = strtol(argv[2], NULL, 10); 

   int sum = 0;
#  pragma omp parallel for num_threads(num_t) reduction(+: sum) 
   for (int i = 1; i<= max_num; i++)
	   sum += i;
   printf("Sum %d\n",sum);

   return 0; 
} 

