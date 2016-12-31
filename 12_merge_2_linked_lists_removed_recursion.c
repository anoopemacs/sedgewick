#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

struct node {
    int key;
    struct node* next;
};
typedef struct node Node;

Node* z;

void list_initialize() {
    z = (Node*)malloc(sizeof *z);
    z->key = INT_MAX;
    z->next = z;
}

void list_printer(Node* n) {
    while(n != z) {
        printf("%c ", n->key);
        n = n->next;
    }
    printf("\n");
}

Node* insert_after(Node* n, int v) {
    Node* t = (Node*)malloc(sizeof *t);
    t->key = v;
    t->next = n->next;
    n->next = t;
    return t;
}

Node* merge(Node* a, Node* b) {
    // combine a & b into a circular list starting
    // and ending in z; then cut it to get linear list starting at z->next
    
    Node* c = z;
    do {
        if (a->key <= b->key) {
            c->next = a;
            c = a;
            a = a->next;
        } else {
            c->next = b;
            c = b;
            b = b->next;
        }
        
    }while(c!=z);
    c = z->next;
    z->next = z;
    
    return c;
}

Node* mergesort0(Node* c) {
    // pending work to be done: refer page170
    return c;
}

int main() {
    list_initialize();
    int input[] = {'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    
    Node* c = (Node*) malloc(sizeof *c);
    c->key = input[0];
    Node* t = c;
    for (int i=1; i!=sizeof(input)/sizeof(input[0]); ++i) {
        t = insert_after(t, input[i]);
    }
    t->next = z;
    // input ends

    mergesort0(c);
    list_printer(c);
    return 0;
}
