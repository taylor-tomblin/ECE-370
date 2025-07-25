#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

#define PI 3.14159

//-------------------
// Complex
//-------------------
// +x: float
// +y: float
//-------------------

struct Complex {
    float x;
    float y;
};

typedef struct Complex Complex;

void complex_print(Complex z, char label[]) {
    printf("\nstruct Complex: %s", label);

    printf("\n       x: %f", z.x);
    printf("\n       y: %f", z.y);

    printf("\n       z: %f + %fi", z.x, z.y);
}

Complex * complex_new(float x_in, float y_in) {
    Complex *ptr;

    ptr = (Complex *) malloc(sizeof(Complex));

    ptr->x = x_in;
    ptr->y = y_in;

    return ptr;
}

void complex_set(Complex *ptr, float x_in, float y_in){

}

void complex_add2(Complex z1, Complex z2, Complex *sum) {
    sum->x = (z1.x + z2.x);
    sum->y = (z1.y + z2.y);
}

Complex * complex_add(Complex z1, Complex z2) {
    // Can also set up as void complex_add(Complex z1, Complex z2, Complex *sum);
    Complex *ptr;

    ptr = (Complex *) malloc(sizeof(Complex));

    ptr->x = z1.x + z2.x;
    ptr->y = z1.y + z2.y;

    return ptr;
}

int main() {
    // z = 5.0 + i7.0
    Complex *z;

    z = complex_new(5.0, 7.0);
    complex_print(*z, "*z");

    Complex *z1 = complex_new(10.0, 20.0);
    Complex *z2 = complex_new(100.0, 200.0);
    Complex sum;

    Complex *s;

    s = complex_add(*z1, *z2);

    complex_print(*s, "*s");

    complex_add2(*z1, *z2, &sum);

    complex_print(*z1, "*z1");
    complex_print(*z2, "*z2");
    complex_print(sum, "sum");

    printf("\n\n");
    return 0;
}
