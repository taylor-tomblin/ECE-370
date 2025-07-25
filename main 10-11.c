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

// API
void node_print(Node *node, char label[]);
Node * node_new(int x_in);
void push_back(Node *head,int x_in);
void push_front(Node *head, int x_in);
void list_print(Node *head, char label[]);
Node * list_new(int n, int x_in[]);
Node * list_new_rand(int n, int min, int max);
void delete_at(Node *head, int k);              // Delete node at index k
void insert_at(Node *head, int x_in, int k);    // Insert new node at index k
Node * list_at(Node *head, int k);              // Return node at index k
int * list_to_array(Node *head, int *n);        // *n number of elements in list
void list_clear(Node *head);                    // Remember to free nodes
void list_append(Node *head, int n, int x_in[]);//

// Function Definitions
void node_print(Node *node, char label[]){
    printf("\n\nstruct Node: %s", label);

    printf("\n          x: %d", node->x);
    printf("\n       next: %p", node->next);
}

Node * node_new(int x_in) {
    Node *node;

    node = (Node *) malloc(sizeof(Node));

    node->x = x_in;
    node->next = NULL;
    return(node);
}

void push_back(Node *head, int x_in) {
    Node *node = head;
    Node *new = node_new(x_in);

    while(node->next !=NULL) {
        node = node->next;
    }
    node->next = new;
}

void push_front(Node *head, int x_in) {
    // TODO put after head
    Node *new = node_new(x_in);
    Node *node = head;

    new->next = head->next;
    head = new;

}

void list_print(Node *head, char label[]){
    Node *node = head;
    int count = 0;

    printf("\n\nLinked List: %s .................................................", label);
    printf("\n          x: %p   %-4d                  head->x    [%d]",&head->x ,head->x,count); //print head
    printf("\n       next: %p   %p      head->next",&head->next ,head->next);
    printf("\n...................................................................\n");

    while(node->next !=NULL) {
        node = node->next;
        count = count + 1;
        printf("\n          x: %p   %-4d                  node->x    [%d]",&node->x ,node->x,count);
        printf("\n       next: %p   %p      node->next\n",&node->next ,node->next);
    }
}

Node * list_new(int n, int x_in[]) {
    // TODO use pushback to make more effiecent
    Node *head = node_new(x_in[0]);
    for(int i=1;i<=n;i++) {
        push_back(head,x_in[i]);
    }
    return(head);
}

Node * list_new_rand(int n, int min, int max) {
    Node *head = node_new(min + rand() % (max-min+1));
    for(int i=1;i<n;i++) {
        int x_in = min + rand() % (max-min+1);
        push_back(head,x_in);
    }
    return(head);
}

void delete_at(Node *head, int k) {
    Node *node = head;

    for(int i=0;i<k;i++) {
        node = node->next;
    }
    node->next = node->next->next;
}

void insert_at(Node *head, int x_in, int k) {
    Node *node = head;
    Node *newNode = node_new(x_in);
    for(int i=0;i<k;i++) {
        node = node->next;
    }
    newNode->next = node->next;
    node->next = newNode;
}

Node * list_at(Node *head, int k){
    // TODO - Return node at index k
}

int * list_to_array(Node *head, int *n) {
    //TODO - return array
}

void list_clear(Node *head) {
    // TODO - use free()
}

void list_append(Node *head, int n, int x_in[]) {
    // TODO - add x_in[] elements to end of linked list
}

int main() {
    Node *myNode;
    myNode = node_new(100);
    node_print(myNode,"myNode");

    // Make a linked list
    Node *head;
    head = node_new(0);
    node_print(head,"head");
    list_print(head,"head");

    push_back(head,100);
    push_back(head,200);
    push_back(head,300);
    list_print(head,"head list");


    int myArray[5] ={0,1,2,3,4};
    Node *new = list_new(4, myArray);
    list_print(new,"new list");

    //new random List
    Node *newList = list_new_rand(10,0,100);
    list_print(newList,"newList");

    printf("\n\n");
    free(head);
    free(myNode);
    return 0;
}
