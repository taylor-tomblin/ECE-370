// Created on iPad.

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

// void rand_dna(int n, char dna[])
char * rand_dna(int n){
   char *dna;

   dna = (char *) malloc((n+ 1) * sizeof(char));

   for(int i= 0; i < n; i++) {
      k = rand() % 4;

      if (k == 0) dna[i] = 'A';
      //... 1 = c
      //... 2 = g
      //... 3 = t
   }
   
   return ;
}

void swap(int *a, int *b) {	// Pass by reference
   int temp;

   temp = *a;

   *a = *b;
   *b = temp;
}

int main() {
   srand(time(NULL));
   
   // Pointer variables
   int *ptr; // pointer variable

   int n = 100;
   int x[1000];

   ptr = &n;
   ptr = (int *) malloc(sizeof(int));

   *ptr = 500;
   // malloc: memory allocation; returns starting address of new allocation

   /* A000 0000: regular variables
   * B000 0000: pointer
   * C000 0000: malloc */

   /* ---------------
   * Address.    Contents.     Variable
   * ----------------
   * B000 0000.    FF00 3245 (g).   ptr.      itunes!

   * A000 0000.    50.            n,ptr
   * B000 0000.    A000 0000.    ptr

   * A000 0000.    100.           n
   * B000 0000.    A000 0000.     ptr
   * C000 0000.    76845 (g).     *ptr

   Allocate space for an areay with 10 elements
   */

   ptr = (int *) malloc(5 * sizeof(int));

   /*
	A000 0000	100			n
   B000 0000	C000 0008	ptr
   C000 0000	500			--memory leak
   C000 0004	(g)			ptr[0]
   C000 0008	(g)			ptr[1]
   C000 000C	(g)			ptr[2]
   C000 0010	(g)			ptr[3]
   C000 0014	(g)			ptr[4]
   */

   /* Pointer arithmetic -------
	ptr = ptr[x + 1]
   */

   // two ways to init pointer var

   char *str;

   str = (char *) malloc(5 * sizeof(char));

   // Memory is all garbage values

   strcpy(str, "home");

   free(strcpy);

   /* Final Memory Table:
   Address			Contents			Variable
   B000 0000		C000 0000		str
	C000 0000		'h'				str[0], *(str + 0)
   C000 0001		'o'				str[1], *(str + 1)
   C000 0002		'm'				str[2]
   C000 0003		'e'				str[3]
   C000 0004		'/0'				str[4]
   */

   float *p;

  // *p = 100.0;   program will crash. need to intiialize

   /* Memory Table
   Address        Contents          Variable
   B000 0000      g                 p        itunes!
   */

   p = (float *) malloc(sizeof(float));

   /* Memory Table
   B000 0000			C000 0000         p
   C000 0000         g                 *p
   */

   int s = 50;
   int t = 90;

   printf("\n\ns: %d    t: %d", s, t);

   swap( &t, &s);
   
   printf("\n\ns: %d    t: %d", s, t);

   char *myDna;
   int size_dna;
   
   scanf("%d", &size_dna);
   
   myDna = rand_dna(size_dna);
   
   // Print memory table
   
   // See Samantha's Notes!!!!

   printf("\n\n")
   return 0;
}