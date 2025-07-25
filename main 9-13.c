#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>


void getRandArray(int n, int x[], int min, int max) {
    for (int i = 0; i < n; i++) {
        x[i] = min + rand() % (max - min + 1);
    }
}

void printArray(int n, int x[], char label[]) {
    printf("\n\n%s: ", label);
    for (int i = 0; i < n; i++) {
        printf("%d ", x[i]);
    }
}

int getValuesInRange(int n, int in[], int out[], int min, int max) {
    /* Function
    1. count = 0
    2. Loop for each i = 0, 1, 2, 3.....
            if in[i] >= min AND in[i[ <= max then
                out[count] = in[i];
                count = count +1
            end if
        end loop
    3. Return count
    */

    int count;

    count = 0;
    for (int i = 0; i < n; i++) {
        if ((in[i] >= min) && (in[i] <= max)) {
            out[count] = in[i];
            count = count + 1;
        }
    }

    return out[count];
}

int getPartialSums(int n, int x[], int psum[]) {
    psum[0] = x[0];

    for(int i = 0; i < n; i++) {
        psum[i] = psum[i - 1] + x[i];
    }

    return psum[n - 1];
}

int main()
{
    srand(time(NULL));

    int in[10], psum[10];
    int n, sum;

    n = 5;

    getRandArray(n, in, 1, 10);
    sum = getPartialSums(n, in, psum);

    printArray(n, in, " in");
    printArray(n, psum, "psum");

    printf("\nSum: %d", sum);

    printf("\n\n");
    return 0;
}
