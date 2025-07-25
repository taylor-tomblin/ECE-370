#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

// STRUCTURES
struct Node {
    char *first; // string payload
    char *last;
    // 3 urls
    // image
    struct Node *next;
};

struct List {
    int n; // # of elements in list
    struct Node *head;
};

// TYPEDEFS
typedef struct Node Node;
typedef struct List List;

char * str_new(char str_in[]);

Node * node_new(char first_in[]);
void node_print(Node *node, char label[]);

List * list_new();
void list_print(List *list,char label[]);
void list_push_back(List *list, char first_in[]);

// FUNCTION DEFINITIONS
char * str_new(char str_in[]) {
    char *str;
    int n = strlen(str_in);
    str = (char *)malloc((n+1)*sizeof(char));
    strcpy(str,str_in);
    return(str);
}

Node * node_new(char first_in[]) {
    Node *node;
    node = (Node *) malloc(sizeof(Node));
    //    int n = strlen(first_in);
    //    node->first = (char *)malloc((n+1)*sizeof(char));
    //    strcpy(node->first,first_in);
    node->first = str_new(first_in);
    node->next = NULL;
    return(node);
}

void node_print(Node *node, char label[]) {
    printf("\n\nstruct Node: %s", label);
    printf(  "\n First Name: %s", node->first);
    printf(  "\n       next: %p", node->next);
}

List * list_new() {
    List *list;
    list = (List *)malloc(sizeof(List));
    list->head = node_new("First Name");
    list->n = 0;
    return(list);
}

void list_print(List *list,char label[]) {
    // TODO
    Node *head;
    head = list->head;

    printf("\n\nstruct List: %s", label);
    printf(  "\n       Head");
    printf("\n------------------------------");
    printf("\n%p first: %s", head, head->first);
    printf("\n%p  next: %p", &head->next, head->next);
    printf("\n------------------------------");
    int count = 0;
    Node *node = head->next;
    while (node != NULL) {
        printf("\n%p first: %s    [%d]", &node, node->first, count);
        printf("\n%p  next: %p", &node->next, node->next);
        node = node->next;
        count = count + 1;
    }

    printf(  "\n        Num: %p", list->n);

}

void list_push_back(List *list, char first_in[]) {

}


/*
 * CSV (comma separated values) Parsing
 * int getCommaIndex(char csv[], int index[]); //return # of commas
 * Example:
 * CSV = one,two,three,four,five
 * index:[3,7,13,18]
*/

int getCommaIndex(char csv[], int index[]) {
    int count=0;

    for(int i=0;i<(int)strlen(csv);i++) {
        if( csv[i] == ',') {
            index[count] = i;
            count++;
        }
    }

    return count;
}

char * get_substr(char str[], int i1, int i2) {
    int len = i2-i1 +1;
    char *sub = (char *)malloc((len + 1) * sizeof(char));

    for(int i=0;i<len;i++) {
        sub[i] = str[i+i1];
    }

    str[len] = '\0';

    return(sub);
}

int parse_csv(char csv[], char *values[]) {
    int numCommas, index[1000], numValues, i1, i2;

    numCommas = getCommaIndex(csv, index);

    numValues = numCommas + 1;

    for (int i = 0; i < numValues; i++) {
        if (i == 0) {
            i1 = 0;
        } else {
            i1 = index[i - 1] + 1;
        }

        if (i == numValues - 1) {
            i2 = strlen(csv) - 1;
        } else {
            i2 = index[i] - 1;
        }
        values[i] = get_substr(csv,i1,i2);
        printf("\n\ni1: %d i2: %d", i1, i2);
    }
}

int main() {
    char csv[] = "one,two,three,four,five";
    int numComma, comma_index[100];
    int numValues;
    char *values[1000];

    numValues = parse_csv(csv, values);
    numComma = getCommaIndex(csv, comma_index);

    printf("\n\nnumComma: %d \nindex: ", numComma);

    for (int i=0; i< numComma; i++) {
        printf("%d",comma_index[i]);
    }

    for (int i = 0; i < numValues; i++) {
        printf("\ni: %d values[%d]: %s",i,i,values[i]);
    }
    printf("\n");
}
