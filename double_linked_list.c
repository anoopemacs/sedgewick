#include <stdio.h>
#include <stdlib.h>

struct node {
    struct node* prev;
    int key;
    struct node* next;
};
typedef struct node Node;

Node* h; Node* z; Node* t;

void forward_printer(Node* h) {
    Node* r = h->next;
    while(r != z) {
        printf("%d ", r->key);
        r = r->next;
    }
    printf("\n");
}

void backward_printer(Node* z) {
    Node* r = z->prev;
    while(r != h) {
        printf("%d ", r->key);
        r = r->prev;
    }
    printf("\n");
}

void initialize() {
    h = (Node*) malloc(sizeof *h);
    z = (Node*) malloc(sizeof *z);
    h->next = z; z->prev = h;
    h->prev = h; z->next = z;
}

Node* insert_after(int v, Node* p) {
    t = (Node*) malloc(sizeof *t);
    t->key = v;
    t->next = p->next;
    t->prev = p;
    p->next->prev = t;
    p->next = t;
    return t;
}

void delete_after(Node* p) {
    Node* delete = p->next;
    p->next = delete->next;
    delete->next->prev = p;
    free(delete);
}

int main() {
    initialize();
    Node* r = h;
    for (int i=1; i!=10; ++i) {
        r = insert_after(i, r);
    }
    forward_printer(h);
    backward_printer(z);
    delete_after(h->next);
    forward_printer(h);
    return 0;
}
