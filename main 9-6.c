#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

FILE *fp;

// API
int get_max(int n, int x[]);
int get_sum(int n, int x[]);
int get_avg(int n, int x[]);
int get_count_in_range(int n, int x[], int min, int max);
int get_values_in_range(int n, int in[], int out[], int min, int max);
void print_array(int n, int x[], char label[]);
void rand_array(int n, int x[], int min, int max);


// Functions
void write_header() {
    fprintf(fp, "\\document{exam}");
}

int get_max(int n, int x[]) {
    /* Algorithm for computing maximum value of an array:
     * 1. max = x[0]
     * 2. for i = 0, 1, 2, ...., n-1
     *      if x[i] > max
     *          max = x[i]
     *      end if
    */

    int max;

    max = x[0];

    for(int i = 0; i < n; i++) {
        if (x[i] > max) {
            max = x[i];
        }
    }

    return max;
}

int get_sum(int n, int x[]) {
    /* Algorithm for computing the sum of an array:
     * 1. 1. sum = x[0]
     * 2. for i = 0, 1, 2, ...., n-1
     *      sum <- sum + x[i]
    */
    int sum;

    for(int i = 0; i < n; i++) {
        sum = sum + x[i];
    }

    return sum;
}

int get_avg(int n, int x[]) {
    int sum;
    float avg;

    sum = get_sum(n, x);

    avg = (float) sum / n;

    return avg;
}

int get_count_in_range(int n, int x[], int min, int max) {
    int count;

    count = 0;

    for(int i = 0; i < n; i++) {
        if((x[i] >= min) && (x[i] <= max)) {
                count = count + 1;
            }
    }

    return count;
}

int get_values_in_range(int n, int in[], int out[], int min, int max) {
    int count;

    count = 0;

    for(int i = 0; i < n; i++) {
            if((in[i] >= min) && (in[i] <= max)) {
                out[count] = in[i];
                count = count + 1;
            }
    }

    return count;
}


void print_array(int n, int x[], char label[]) {
    printf("\n%s: ", label);

    for(int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
}

void rand_array(int n, int x[], int min, int max) {
    for(int i = 0; i < n; i++) {
        x[i] = min + rand() % (max - min + 1);
    }
}


int main()
{
    srand(time(NULL));
    /* This starts Assignment 1
    * fp = fopen("student.tex", "w");

    * Program that will code a LaTex Document
    * write_header();
    */

    // Find the max value of an array
    int x[10] = {89, 77, 86, 100, 74, 92, 45, 98, 55, 79};

    int max;

    max = get_max(10, x);

    printf("\nMax: %d", max);


    // Find the max value of a random array
    int scores[100];

    rand_array(50, scores, 70, 100);
    print_array(50, scores, "scores");

    max = get_max(50, scores);

    printf("\nMax of Array: %d", max);


    // Find the sum of an array
    int s[3] = {10, 50, 20};

    rand_array(3, s, 0, 50);
    print_array(3, s, "s");
    printf("\nSum: %d\n", get_sum(3, s));


    //Find the average of an array
    printf("\nAverage: %f\n", get_avg(3, s));


    // Find the count in range
    printf("\nCount: %d\n", get_count_in_range(3, s, 0, 50));


    // Find values in range
    int out[100];
    int countA;

    countA = get_values_in_range(50, scores, out, 90, 100);

    print_array(countA, out, "out");


    printf("\n\n");
    return 0;
}
