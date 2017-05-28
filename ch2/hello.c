/* File:     hello.c
 *
 * Purpose:  A serial program, hello
 *
 * Compile:  gcc -g -Wall hello.c -o hello 
 * Run:      ./hello <number of input>
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
   int num_t = strtol(argv[1], NULL, 10); 
   printf("The serial program says hello to you with input %d!\n", num_t);
   return 0; 
} 

