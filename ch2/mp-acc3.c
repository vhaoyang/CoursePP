/* File:     mp-acc3.c
 *
 * Purpose:  A parallel program that uses OpenMP reduction
 *
 * Compile:  gcc -g -Wall -fopenmp mp-acc3.c -o mp-acc3
 * Run:      ./mp-acc3 <max number of accumulation> <number of threads>
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
   int item = max_num/num_t;
#  pragma omp parallel num_threads(num_t) reduction(+: sum) 
{
   int id = omp_get_thread_num();
   int count_t = omp_get_num_threads();
   for (int i = item*id+1; i<= (id==count_t-1?max_num:item*(id+1)); i++)
	   sum += i;
   printf("Thread %d & sum %d\n", id,sum);
}
   printf("sum %d\n",sum);

   return 0; 
} 

