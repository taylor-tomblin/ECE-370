#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define PI 3.14159265

// Quiz
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
// End of Quiz

// Sequences
void reverse(int n, int x[], int y[]) {
    for (int i = 0; i < n; i++) {
        y[i] = x[n - i - 1];
    }
}

int delete_at_k(int n, int x[], int y[], int k) {
    for (int i = 0; i < n - 1; i++) {
        if (i < k) {
            y[i] = x[i];
        } else {
            y[i] = x[i + 1];
        }
    }

    return n - 1;
}

int sampleTAxis(float t[], float tmin, float tmax, float step) {
    int n;

    n = (tmax - tmin) / step + 1;

    for (int i = 0; i < n; i++) {
        t[i] = tmin + i * step;
    }

    return n;
}

void getCosSample(int n, float x[], float y[], float alpha, float f0) {
    for (int i = 0; i < n; i++) {
        y[i] = exp(-alpha * x[i]) * cos(2 * PI * f0);
    }
}

void printArrayFloat(int n, float x[],char label[]) {
    printf("\n%s: ",label);
    for(int i=0;i<n;i++) {
        printf("%-7.2f ",x[i]);
    }
    printf("\n");
}

int main()
{
    srand(time(NULL));
    printf("\n\n");

    // Quiz
    int data[20], pos[20], neg[20];
    int n_pos, n_neg;

    getRandArray(20, data, -5, 5);

    n_pos = getValuesInRange(20, data, pos, 1, 5);
    n_neg = getValuesInRange(20, data, neg, -5, -1);

    printArray(20, data, "data");
    printArray(n_neg, neg, "neg:");
    printArray(n_pos, pos, "pos:");
    // End of Quiz

    printf("\n\n");

    // Sequences
    int n = 10;

    getRandArray(n, data, -5, 5);

    n_pos = getValuesInRange(n, data, pos, 1, 5);
    n_neg = getValuesInRange(n, data, neg, -5, -1);

    int rev[20], del[20];

    reverse(n, data, rev);
    int n_del = delete_at_k(n, data, del, 2);

    printArray(20, data, "data");
    printArray(n_neg, neg, "neg:");
    printArray(n_pos, pos, "pos:");

    printArray(n, rev, "rev: ");
    printArray(n_del, del, "del: ");

    float t[50000], y[50000];

    n = sampleTAxis(t, 0, 1.0, .1);
    getCosSample(n, t, y, .5, 5);
    printArrayFloat(n, t, "Time");
    // End of Sequences

    printf("\n\n");
}
