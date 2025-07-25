#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <math.h>

// Structure Definitions

// ----------------
// Circle
// ----------------
// +x: int
// +y: int
// +z: int
// ----------------

struct Circle {
    int x; // center: (x,y)
    int y;
    int r; // radius: r
};

struct Fill {
    int red;    //Rgb
    int green;  //rGb
    int blue;   //rgB
    int opacity;
};

struct Stroke {
    int red;
    int green;
    int blue;
    int opacity;
    int width ;
};

// ----------------
// Student
// ----------------
// +firstName: char[100]
// +lastName: char[100]
// +gpa: float
// +id: int
// ----------------


struct Student {
    char firstName[100];
    char lastName[100];
    float gpa;
    int id;
};

// ----------------
// Student
// ----------------
// +firstName: * char
// +lastName: * char
// +gpa: float
// +id: int
// ----------------
struct Student2 {
    char *firstName;
    char *lastName;
    float gpa;
    int id;
};

// ----------------
// Complex
// ----------------
// +x: int
// +y: int
// ----------------
struct Complex {
    int x;
    int y;
};

// Typpedefs
typedef struct Circle Circle;
typedef struct Student Student;
typedef struct Student2 Student2;
typedef struct Fill Fill;
typedef struct Stroke Stroke;
typedef struct Complex Complex;

// API
void circle_set(Circle *cptr, int x_in, int y_in, int r_in);
void circle_print(Circle circle, char label[]);
Circle * circle_new(int x_in, int y_in, int r_in);

void student_set(Student *ptr, char firstName_in[], char lastName_in[],float gpa_in, int id_in);
void student_print(Student student, char label[]);
Student2 * student_new(char firstName_in[], char lastName_in[],float gpa_in, int id_in);
void student2_set(Student2 *ptr, char firstName_in[], char lastName_in[],float gpa_in, int id_in);
void student2_print(Student2 s, char label[]);

void myDrawCircle(Circle myCircle, Fill myFill, Stroke myStroke);

// Function Definitions
void circle_set(Circle *cptr, int x_in, int y_in, int r_in) {
    cptr->r = r_in;
    cptr->y = y_in;
    cptr->x = x_in;
}
void circle_print(Circle circle, char label[]) {
    printf("\nStruct Circle: %s ----------------\n",label);
    printf("x: %d\ny: %d\nr: %d\n", circle.x, circle.y, circle.r);
}
Circle * circle_new(int x_in, int y_in, int r_in) {
    Circle *c; // need pointer otherwise variable is made in stack and then lost
    c = (Circle *) malloc(sizeof(Circle)); // have to use this to put on heap
    c->x = x_in;
    c->y = y_in;
    c->r = r_in;
    return c;
}

void student_set(Student *ptr, char firstName_in[], char lastName_in[],float gpa_in, int id_in) {
    strcpy(ptr->firstName,firstName_in);
    strcpy(ptr->lastName,lastName_in);
    ptr->gpa = gpa_in;
    ptr->id = id_in;
}
void student_print(Student student, char label[]) {
    printf("\nStruct Student: %s ----------------",label);
    printf("\nfirst name: %s",student.firstName);
    printf("\n last name: %s",student.lastName);
    printf("\n       gpa: %1.3f",student.gpa);
    printf("\n        id: %d\n",student.id);
}
Student2 * student_new(char firstName_in[], char lastName_in[],float gpa_in, int id_in) {
    Student2 *s; // need pointer otherwise variable is made in stack and then lost
    s = (Student2 *) malloc(sizeof(Student2));
    s->firstName = firstName_in;
    s->lastName = lastName_in;
    s->gpa = gpa_in;
    s->id = id_in;
}
void student2_set(Student2 *ptr, char firstName_in[], char lastName_in[],float gpa_in, int id_in){
    ptr->firstName = firstName_in;
    ptr->lastName = lastName_in;
    ptr->gpa = gpa_in;
    ptr->id = id_in;
}
void student2_print(Student2 s, char label[]) {
    printf("\nStruct Student2: %s ----------------",label);
    printf("\nfirst name: %s",s.firstName);
    printf("\n last name: %s",s.lastName);
    printf("\n       gpa: %1.3f",s.gpa);
    printf("\n        id: %d\n",s.id);
}

int main()
{
    //regular struct variables
    struct Circle myCircle;     // use . to acess member vars

    // ----------------// ----------------// ----------------
    // Address              Content             Variable
    // ----------------// ----------------// ----------------
    // A000 0000          -6846 (garbage)    myCircle.x
    // A000 0004           7575 (garbage)    myCircle.y
    // A000 0008          -324  (garbage)    myCircle.r

    myCircle.x = 100;
    myCircle.y = 200;
    myCircle.r = 50;

    //pointer struct variable
    struct Circle *ptr; // Use -> to access member vars

    // ----------------// ----------------// ----------------
    // Address              Content             Variable
    // ----------------// ----------------// ----------------
    // A000 0000           100               myCircle.x
    // A000 0004           200               myCircle.y
    // A000 0008           500               myCircle.r
    // B000 0000           FF65 8884 (g)     ptr            //no allocated space yet

    //ptr->x = 500;   Program Crashes - Need to init ptr

    /* Two ways to init ptr
        1. Use the address of an existing variable
        2. malloc
    */
        ptr = &myCircle;

    // ----------------// ----------------// ----------------// ----------------
    // Address              Content             Variable
    // ----------------// ----------------// ----------------// ----------------
    // A000 0000           100               myCircle.x and ptr->x
    // A000 0004           200               myCircle.y and ptr->y
    // A000 0008           500               myCircle.r and ptr->r
    // B000 0000           A000 0000         ptr

    ptr->x = 500;
    (*ptr).y = 700;

    // ----------------// ----------------// ----------------// ----------------
    // Address              Content             Variable
    // ----------------// ----------------// ----------------// ----------------
    // A000 0000           500               myCircle.x and ptr->x
    // A000 0004           700               myCircle.y and ptr->y
    // A000 0008           500               myCircle.r and ptr->r
    // B000 0000           A000 0000         ptr

    ptr = (struct Circle *) malloc(sizeof(struct Circle));

    // ----------------// ----------------// ----------------// ----------------
    // Address              Content             Variable
    // ----------------// ----------------// ----------------// ----------------
    // A000 0000           500               myCircle.x
    // A000 0004           700               myCircle.y
    // A000 0008           500               myCircle.r
    // B000 0000           C000 0000         ptr
    // C000 0000          -59685(g)          (*ptr).x or ptr->x
    // C000 0004           5678 (g)          (*ptr).y or ptr->y
    // C000 0008           2123 (g)          (*ptr).r or ptr->r

    ptr->x = 1;
    ptr->y = 2;
    ptr->r = 3;

    /*printf("\n\nstruct: myCircle ----------------");
    printf("\n     x: %d",myCircle.x);
    printf("\n     y: %d",myCircle.y);
    printf("\n     r: %d",myCircle.r);

    printf("\n\nstruct: *ptr ----------------");
    printf("\n     x: %d",ptr->x);
    printf("\n     y: %d",ptr->y);
    printf("\n     r: %d",ptr->r);*/

    Circle yourCircle; // Circle is a type (we created)
                       // And we're doing a var declaration

    circle_set(&yourCircle,10,20,5);
    circle_print(yourCircle,"yourCircle");

    Circle *p; // because we used typedef above
    p = (Circle *) malloc(sizeof(Circle));
    circle_set(p,2,4,6);
    circle_print(*p,"*p");

    //----------------//----------------//----------------//----------------
    //Address---------//Contents--------//Variable--------//----------------
    //----------------//----------------//----------------//----------------
    //B000 0000         C000 0000         ptr

    printf("\n\n %p     %p\n", &ptr, ptr);

    Circle *ourPtr; // by itself cause error with no space allocation
    ourPtr = circle_new(40,60,90);

    Circle *herPtr = circle_new(1000,2000,55);

    //STUDENT

    Student myStudent;
    student_set(&myStudent,"Paul","Watta",3.21,868585);
    student_print(myStudent,"myStudent");

    Student2 me;

    // ----------------// ----------------// ----------------// ----------------
    // Address              Content             Variable
    // ----------------// ----------------// ----------------// ----------------
    // A000 0000           FF44 86000 (g)   me.firstName
    // A000 0004           FF21 6780 (g)    me.lastName
    // A000 0008           9785.677 (g)     gpa
    // A000 000C           8786870 (g)      id

    student2_set(&me,"Paul2","Watta2",2.10,555555);
    student2_print(me,"myStudent");

    printf("\n\n");
    return 0;
}
