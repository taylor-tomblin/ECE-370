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

    //-----------------------------------------
    // Address		Contents		Variable
    //-----------------------------------------
    // B000 0000	g				head
    // B000 0004	g				nodeA
    // B000 0008	g				nodeB
    // B000 000C	g				nodeC

    head = (Node *) malloc(sizeof(Node));

    //-----------------------------------------
    // Address		Contents		Variable
    //-----------------------------------------
    // B000 0000	g				head
    // B000 0004	g				nodeA
    // B000 0008	g				nodeB
    // B000 000C	g				nodeC

    // C000 0000	g				head->x
    // C000 0004	g				head->next

    nodeA = (Node *) malloc(sizeof(Node));
    nodeB = (Node *) malloc(sizeof(Node));
    nodeC = (Node *) malloc(sizeof(Node));

    //-----------------------------------------
    // Address		Contents		Variable
    //-----------------------------------------
    // B000 0000	C000 0000		head
    // B000 0004	g				nodeA
    // B000 0008	g				nodeB
    // B000 000C	g				nodeC

    // C000 0000	g				head->x
    // C000 0004	g				head->next
    // C100 0000	g				nodeA->x
    // C100 0004	g				nodeA->next
    // C200 0000	g				nodeB->x
    // C200 0004	g				nodeB->next
    // C300 0000	g				nodeC->x
    // C300 0004	g				nodeC->next

    head->x = 0;
    head->next = nodeA;

    nodeA->x = 100;
    nodeA->next = nodeB;

    nodeB->x = 50;
    nodeB->next = nodeC;

    nodeC->x = 70;

    Node *node, *prev, *headnode;

    int x[3] = {100, 560, 70};

    headnode = (Node *) malloc(sizeof(Node));

    headnode->x = 0;

    prev = headnode;

    node = (Node *) malloc(sizeof(Node));

    node->x = x[0];
    prev->next = node;

    prev = node;

    node = (Node *) malloc(sizeof(Node));

    node->x = x[1];
    prev->next = node;

    prev = node;

    node = (Node *) malloc(sizeof(Node));

    node->x = x[2];
    prev->next = node;

    node->next = NULL;

    prev = node;

    printf("\n\n");
    return 0;
}
