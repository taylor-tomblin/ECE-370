#define CRT_SECURE_NO_WARNINGS

#define PI 3.14159265 // this is a constant

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

int main()
{
    srand(time(NULL));

    // Print address to screen:
    int m;

    //scanf("Please enter a value:   %d", &m); <= calls for user input
    m = 80;  // tried to have a user input a value (something fancy), but it didn't work with qt

    printf("\nAddress                      Contents          Memory");   // memory table
    printf("\n%p               %d          m", &m, m);


    // Print strings:
    char str[7];
    char s[7] = {'h', 'i', ' ', 'y', 'o', 'u', '\0'};
    char s2[7] = "hi you\0";

    str[0] = 'h';
    str[1] = 'i';
    str[2] = ' ';
    str[3] = 'y';
    str[4] = 'o';
    str[5] = 'u';
    str[6] = '\0';  // says when string is done

    printf("\n\nstr[0]: %c", str[0]);
    printf("\nstr[1]: %c", str[1]);
    printf("\nString: %s", str);

    printf("\n\nString: %s", s);

    printf("\n\nString: %s", s2);

    printf("\n\nAddress                      Contents          Memory");
    printf("\n%p               %d          str[0]", &str[0], str[0]);
    printf("\n%p               %d          str[1]", &str[1], str[1]);
    printf("\n%p               %d          str[2]", &str[2], str[2]);
    printf("\n%p               %d          str[3]", &str[3], str[3]);
    printf("\n%p               %d          str[4]", &str[4], str[4]);
    printf("\n%p               %d          str[5]", &str[5], str[5]);
    printf("\n%p               %d          str[6]", &str[6], str[6]);

    printf("\n\n%p               %d          s[0]", &s[0], s[0]);
    printf("\n%p               %d          s[1]", &s[1], s[1]);
    printf("\n%p               %d          s[2]", &s[2], s[2]);
    printf("\n%p               %d          s[3]", &s[3], s[3]);
    printf("\n%p               %d          s[4]", &s[4], s[4]);
    printf("\n%p               %d          s[5]", &s[5], s[5]);
    printf("\n%p               %d          s[6]", &s[6], s[6]);


    // Print a String with a Memory Table to a File
    FILE *fp;

    char st[16] = {'m', 'y', ' ', 'c', 'a', 't', ' ', 'i', 's', ' ', 'c', 'r', 'a', 'z', 'y', '\0'};

    fp = fopen("C:/Users/tjt07/iCloudDrive/School/U of M - Dearborn/Fall 2023/ECE 370 - Advanced Software Techniques/C-Projects/270-Review/filePrintTest.txt", "w");
        /* w: write to a file
         * r: read from a file  */
    fprintf(fp, "String: %s",st);

    fprintf(fp, "\n\nAddress                      Contents      Memory");
    fprintf(fp, "\n%p               %.3d          st[0]", &st[0], st[0]);
    fprintf(fp, "\n%p               %.3d          st[1]", &st[1], st[1]);
    fprintf(fp, "\n%p               %.3d          st[2]", &st[2], st[2]);
    fprintf(fp, "\n%p               %.3d          st[3]", &st[3], st[3]);
    fprintf(fp, "\n%p               %.3d          st[4]", &st[4], st[4]);
    fprintf(fp, "\n%p               %.3d          st[5]", &st[5], st[5]);
    fprintf(fp, "\n%p               %.3d          st[6]", &st[6], st[6]);
    fprintf(fp, "\n%p               %.3d          st[7]", &st[7], st[7]);
    fprintf(fp, "\n%p               %.3d          st[8]", &st[8], st[8]);
    fprintf(fp, "\n%p               %.3d          st[9]", &st[9], st[9]);
    fprintf(fp, "\n%p               %.3d          st[10]", &st[10], st[10]);
    fprintf(fp, "\n%p               %.3d          st[11]", &st[11], st[11]);
    fprintf(fp, "\n%p               %.3d          st[12]", &st[12], st[12]);
    fprintf(fp, "\n%p               %.3d          st[13]", &st[13], st[13]);
    fprintf(fp, "\n%p               %.3d          st[14]", &st[14], st[14]);
    fprintf(fp, "\n%p               %.3d          st[15]", &st[15], st[15]);

    fclose(fp);


    // Grades
    int grades[] = {};


    printf("\n\n");
    return 0;
}
