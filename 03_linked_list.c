#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* next;
};
typedef struct node Node;

Node* head; Node* z; Node* t;

void list_printer(Node* head) {
    Node* r = head->next; //skip dummy key of head
    while(r->next != r) {
        printf("%d  ", r->key);
        r = r->next;
    }
    printf("\n");
}

void list_initialize() {
    head = (Node*) malloc(sizeof *head);
    z = (Node*) malloc(sizeof *z);
    head->key = 0; //dummy
    head->next = z;
    z->next = z;
}

void delete_next(Node* t) {
    t->next = t->next->next;
}

Node* insert_after(int v, Node* t) {
    Node* x;
    x = (Node*)malloc(sizeof *x);
    x->key = v;
    x->next = t->next;
    t->next = x;
    return x;
}

void move_next_to_front(Node* t) {
    Node* y = t->next;
    t->next = t->next->next;
    y->next = head->next;
    h->next = y;
}

int main() {
    list_initialize();
    Node* t = insert_after(1, head);
    for (int i=2; i!=10; ++i) {
        t = insert_after(i, t);
    }
    list_printer(head);
    return 0;
}
