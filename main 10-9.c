#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#include <string.h>

struct Node {
    int x;   // payload
    struct Node *next;   // pointer to the next node
};
\
typedef struct Node Node;



int main(int argc, char **argv)
{
    printf("\nargc: %d", argc);

    for(int i = 0; i < argc; i++) {
        printf("\nargc[%d]: %s", i, argv[i]);
    }

    Node *head, *nodeA, *nodeB, *nodeC;

    head = (Node *) malloc(sizeof(Node));

    nodeA = (Node *) malloc(sizeof(Node));
    nodeB = (Node *) malloc(sizeof(Node));
    nodeC = (Node *) malloc(sizeof(Node));

    head->x = 0;
    head->next = nodeA;

    nodeA->x = 100;
    nodeA->next = nodeB;

    nodeB->x = 50;
    nodeB->next = nodeC;

    nodeC->x = 70;
    nodeC->next = NULL;

    printf("\n\n");
    return 0;
}
