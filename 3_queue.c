#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* next;
};
typedef struct node Node;

Node* h; Node* z; Node* t; 

void queue_printer(Node* h) {
    Node* r = h->next;
    while(r != z) {
        printf("%d ", r->key);
        r = r->next;
    }
    printf("\n");
}

int queue_empty_p() {
    return (h->next == z);
}

void queue_initialize() {
    h = (Node*) malloc(sizeof *h);
    z = (Node*) malloc(sizeof *z);
    h->key = 0; z->key = 0;
    h->next = z; z->next = z;
}

void put(int v) {
    t = (Node*) malloc(sizeof *t);
    t->key = v; t->next = h->next;
    h->next = t;
}

int get() {
    Node* r = h;
    if (queue_empty_p()) return -1;    
    while (r->next->next != z) r = r->next;
    Node* delete = r->next;
    r->next = z;
    int ret = delete->key;
    
    free(delete);
    return ret;
}

int main() {
    queue_initialize();
    put(1); put(2); put(3); put(4); put(5);
    queue_printer(h);
    get(); get(); get();
    queue_printer(h);
    return 0;
}
