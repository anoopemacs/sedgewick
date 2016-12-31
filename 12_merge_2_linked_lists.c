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

int main() {
    list_initialize();
    // a = {9, 8, 7}, b = {4, 3, 2, 1}
    
    Node* a = (Node*) malloc(sizeof *a);
    Node* b = (Node*) malloc(sizeof *b);
    a->key = 9; b->key = 4;
    Node* t = a;
    for (int i=8; i>=7; --i) {
	t = insert_after(t, i);
    }
    t->next = z;

    t = b;
    for (int i=3; i>=1; --i) {
	t = insert_after(t, i);
    }
    t->next = z;
    // input ends

    t = merge(a, b);
    while(t != z) {
	printf("%d ", t->key);
	t = t->next;
    }
    
    
    return 0;
}
