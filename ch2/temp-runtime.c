/* File:     mp-for2.c
 *
 * Purpose:  A parallel program that uses OpenMP for
 *
 * Compile:  gcc -g -Wall -fopenmp mp-for2.c -o mp-for2 
 * Run:      ./mp-for2 <number of threads>
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
   int end_num = strtol(argv[2], NULL, 10);

   int sum = 0;
   double t1 = omp_get_wtime( );
#  pragma omp parallel for num_threads(num_t) reduction(+: sum) 
   for (int i = 1; i<= end_num; i++)
	   sum += i;
   double t2 = omp_get_wtime( );
   printf("Sum %d & Time %.16g\n",sum,t2-t1);

   return 0; 
} 

