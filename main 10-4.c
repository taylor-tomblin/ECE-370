#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <math.h>
#include <string.h>

struct rgb {
    int red;
    int blue;
    int green;
    int alpha;
};

typedef struct rgb rgb;

// API
rgb * rgb_new(int red_in, int green_in, int blue_in, int alpha_in);
void rgb_set(rgb *ptr, int red_in, int green_in, int blue_in, int aplha_in);
void rgb_print(rgb rgb, char label[]);

char * dna_rand(int n);

// Function Definitions
rgb * rgb_new(int red_in, int green_in, int blue_in, int alpha_in) {
    rgb * ptr;

    ptr = (rgb *) malloc(sizeof(rgb));

    ptr->red = red_in;
    ptr->green = green_in;
    ptr->blue = blue_in;
    ptr->alpha = alpha_in;

    return ptr;
}

void rgb_set(rgb *ptr, int red_in, int green_in, int blue_in, int alpha_in) {
    ptr->red = red_in;
    ptr->green = green_in;
    ptr->blue = blue_in;
    ptr->alpha = alpha_in;
}

void rgb_print(rgb rgb, char label[]) {
    printf("\nRGB struct: %s", label);

    printf("\n          red: %d", rgb.red);
    printf("\n          green: %d", rgb.green);
    printf("\n          blue: %d", rgb.blue);
    printf("\n          alpha: %d", rgb.alpha);
}

char * dna_rand(int n) {
    char bases[] = "ACGT";

    char *dna = (char *) malloc((n - 1) * sizeof(char));

    for(int i = 0; i < n; i++) {
        n = rand() % 4;
        dna[i] = bases[n];
    }

    dna[n] = '\0';

    return dna;
}

int main() {
    rgb *myColor;

    int q[10];
    rgb colors[10];
    char str[100];

    myColor = rgb_new(0, 125, 125, 100);

    rgb_print(*myColor, "*myColor");

    printf("\n\ncolors: %p     &colors[0]: %p", colors, &colors[0]);

    for(int i = 0; i < 10; i++) {
        rgb_set(&colors[i], rand() % 256, rand() % 256, rand() % 256, rand() % 256);
    }

    for(int i = 0; i < 10; i++) {
        sprintf(str, "colors[%d]", i);
        rgb_print(colors[i], str);
    }

    int n;
    rgb *p;

    printf("\n\nPlease enter number of colors needed:");
    scanf("%d", &n);

    p = (rgb *) malloc( n * sizeof(rgb));

    for(int i = 0; i < n; i++) {
        rgb_set(&p[i], rand() % 256, rand() % 256, rand() % 256, rand() % 256);
    }

    for(int i = 0; i < n; i++) {
        sprintf(str, "p[%d]", i);
        rgb_print(p[i], str);
    }

    char *myDna;

    myDna = dna_rand(200);

    printf("\n\nmyDna: %s ", myDna);

    char *pop[10];
    /* Above is an array of pointer variables
     * This allocates space for 10 addresses
     * Each address is pointing to itunes!!!
     * */

    // pop[0] = dna_rand(50);
    // pop[1] = dna_rand(200);

    printf("\n\n");

    for(int i = 0; i < 20; i++) {
        pop[i] = dna_rand(20);   // dna_rand(20 + rand() % 30);

        printf("\n\npop[%d]: %s ", i, pop[i]);
    }

    char **myPop;

    myPop = (char **) malloc(5 * sizeof(char *));

    for(int i = 0; i < 5; i++) {
        myPop[i] = dna_rand(10);
    }

    printf("\n\n");
    return 0;
}
