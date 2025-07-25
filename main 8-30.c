#define _CRT_SECURE_NO_WARNINGS

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

int main()
{
    srand(time(NULL));

    // Refresher from 270
    int x = 10;
    float p = 8.5;

    printf("\nx: %-5d p: %-7.2f", x, p);


    // Random Number:
    printf("\n\nRAND_MAX: %d", RAND_MAX);


    /* prototype:   int rand()
     * returns a number between 0 and RAND_MAX (32767) */
    int r;

    r = rand();

    printf("\n\nr: %d", r);


    /* prototype:   int rand()
     * returns a number between 0 and 10 */
    r = rand() % 11;

    printf("\n\nr: %d", r);


    /* prototype:   int rand()
     * returns a number between 10 and 50 */
    r = 10 + rand() % 41;       // r = min + rand() % (max - min + 1);   good for generating data

    printf("\n\nr: %d", r);


    // Random float:
    float q;

    q = (float)rand() / RAND_MAX;       // must cast otherwise, float will always be 0

    printf("\n\nq: %f", q);


    //Switch Statement
    char c = 'T';

    switch(c) {
    case 'H':
        printf("\n\nHeads!");
        break;
    case 'T':
        printf("\n\nTails!");
        break;
    default:
        printf("\n\nNeither heads or tails!");
    }


    //Algorithms
    int y[10] = {75, 90, 77, 94, 95, 100, 83, 87, 92, 58};
    int n = 10;
    int count;

    /* Counting the number of A grades
     * 1. count = 0
     * 2. Loop: for i = 0, 1, 2, ..., n-1
     *              if x_i >= 90
     *                  count = count + 1
     *              end if
     *          end for
    */
    count = 0;
    for (int i = 0; i < n; i++) {
        if (y[i] >= 90) {
            count = count +1;
        }
    }

    printf("\n\nNumber of A grades: %d", y);

    printf("\n\n");
    return 0;
}
