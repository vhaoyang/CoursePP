/* File:     mp-acc1.c
 *
 * Purpose:  A serial program that uses for
 *
 * compile:  gcc -g -Wall mp-acc.c -o mp-acc1 
 * Run:      ./mp-acc1 <max number of accumulation>
 * 
 * Input:    
 * Output:   
 *
 */
#include <stdio.h>
#include <stdlib.h>
/*--------------------------------------------------------------------*/
/* main */
/*--------------------------------------------------------------------*/
int main(int argc, char* argv[]) {
  int max_num = strtol(argv[1], NULL, 10); 
  int sum =0;
  for (int i=1; i<=max_num; i++)
    sum += i;
  printf("Sum %d\n", sum);
  return 0; 
} 

