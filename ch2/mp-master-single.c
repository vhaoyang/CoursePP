/* File:     mp-master-single.c
 *
 * Purpose:  A parallel program that uses OpenMP master & single
 *
 * Compile:  gcc -g -Wall -fopenmp mp-master-single.c -o mp-master-single 
 * Run:      ./mp-master-single 
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

#  pragma omp parallel num_threads(4) 
   {
	   printf("thread %d in line %d\n",omp_get_thread_num(), __LINE__);
#  pragma omp master
	   printf("[master]thread %d in line %d\n",omp_get_thread_num(), __LINE__);
#  pragma omp single
	   printf("[single]thread %d in line %d\n",omp_get_thread_num(), __LINE__);
   }

   return 0; 
} 

