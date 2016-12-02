#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *next;
}; //static struct => all inside it are static as well
typedef struct node Node;
static Node *head, *z, *t;

void stack_printer(Node* head) {
    Node* run = head->next;//skip head dummy key
    while (run->next != run) {
        printf("%d ", run->key);
        run = run->next;
    }
    printf("\n");
}

void stack_init() {
    head = (Node*) malloc(sizeof *head);
    z = (Node*) malloc(sizeof *z);
    head->next = z; head->key = 0;
    z->next = z;
}

void push(int v) {
    t = (Node*) malloc(sizeof *t);
    t->key = v;
    t->next = head->next;
    head->next = t;
}

int pop() {
    int x;
    t = head->next;
    head->next = t->next;
    x = t->key;
    free(t);
    return x;
}

int stack_empty_p() {
    return head->next == z;
}

int main() {
    stack_init();
    push(1);    push(2);    push(3);    push(4);    push(5);
    stack_printer(head);
    pop(); pop();
    stack_printer(head);
    return 0;
}
