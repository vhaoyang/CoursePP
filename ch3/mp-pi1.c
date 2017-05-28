/* File:     mp-pi1.c
 * Purpose:  Estimate pi using OpenMP and the formula
 *
 *              pi = 3 + 4*[1/2*3*4 - 1/4*5*6 + 1/6*7*8 - 1/8*9*10 + 1/9*10*11 - . . . ]
 *
 * Compile:  gcc -g -Wall -fopenmp -lm mp-pi1.c -o mp-pi1              
 * Run:      ./mp-pi1 <n>
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

int main(int argc, char* argv[]) {
   long long n, i;
   double factor = 1.0;
   double sum = 0.0;

   n = strtoll(argv[1], NULL, 10);
   for (i = 0; i < n; i++) {
      sum += factor/((2*i+2)*(2*i+3)*(2*i+4));
	  factor = -factor;
   }
   sum = 3.0+4.0*sum;
   printf("With n = %lld terms,\n", n);
   printf("   Our estimate of pi = %.14f\n", sum);
   printf("                   pi = %.14f\n", 4.0*atan(1.0));

   return 0;
}  

