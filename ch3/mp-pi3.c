/* File:     mp-pi3.c
 * Purpose:  Estimate pi using OpenMP and the formula
 *
 *              pi = 3 + 4*[1/2*3*4 - 1/4*5*6 + 1/6*7*8 - 1/8*9*10 + 1/9*10*11 - . . . ]
 *
 * Compile:  gcc -g -Wall -fopenmp -lm mp-pi3.c -o mp-pi3              
 * Run:      mp-pi3 <n> <thread_count>
 *           thread_count is the number of threads
 *           n is the number of terms of the series to use
 *
 * Input:    none            
 * Output:   The estimate of pi and the value of pi computed by the
 *           arctan function in the math library
 *
 */        

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <omp.h> 

void Usage(char* prog_name);

/*------------------------------------------------------------------
*Function:  main   
*
*/
int main(int argc, char* argv[]) {
   long long n, i;
   int count_t;
   double factor;
   double sum = 0.0;

   if (argc != 3) Usage(argv[0]);
   n = strtoll(argv[1], NULL, 10);
   count_t = strtol(argv[2], NULL, 10);
   if (count_t < 1 || n < 1) Usage(argv[0]);

#  pragma omp parallel for num_threads(count_t) \
      reduction(+: sum) 
   for (i = 0; i < n; i++) {
      factor = (i % 2 == 0) ? 1.0 : -1.0; 
      sum += factor/((2*i+2)*(2*i+3)*(2*i+4));
   }

   sum = 3.0+4.0*sum;
   printf("With n = %lld terms and %d threads,\n", n, count_t);
   printf("   Our estimate of pi = %.14f\n", sum);
   printf("                   pi = %.14f\n", 4.0*atan(1.0));
   return 0;
}

/*------------------------------------------------------------------
 * Function:  Usage
 * Purpose:   Print a message explaining how to run the program
 * In arg:    prog_name
 */
void Usage(char* prog_name) {
   fprintf(stderr, "usage: %s <n> <count_t>\n", prog_name);  /* Change */
   fprintf(stderr, "   n is the number of terms and should be >= 1\n");/* Change */
   fprintf(stderr, "   count_t is the number of threads >= 1\n");  
   exit(0);
}  /* Usage */
