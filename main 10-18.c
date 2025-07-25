#include <stdio.h>

int main() {
    /*
    csv: one,two,three,four,five

    csv: Paul,Watta,8458485,111 Mocking Bird Lane,Detroit

    index: 3, 7, 13, 18

    ----------------------------------------------------
    i |  i1  |  i2  |    i1          |    i2
    ----------------------------------------------------
    0 |  0   |  2   |  0             | index[0] - 1
    1 |  4   |  6   |  index[0] + 1  | index[1] - 1
    2 |  8   |  12  |  index[1] + 1  | index[2] - 1
    3 |  14  |  17  |  index[2] + 1  | index[3] - 1
    ----------------------------------------------------
    */

    // See image in folder for how to upload image

    printf("\n\n");
    return 0;
}
