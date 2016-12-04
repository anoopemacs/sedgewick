#include <stdio.h>
#include <stdlib.h>

struct node {
    char info;
    struct node* l;
    struct node* r;
};
typedef struct node Node;
Node* x;
Node* z;

void tree_printer(Node* root) {
    Node* r = root;    
    printf("%c ", r->info);
    
    if (root->l != z) tree_printer(r->l);
    if (root->r != z) tree_printer(r->r);    
}

//stack from ch3 modified to store pointers
//stack is used to temporarily store scanf input
struct stack_node {
    Node* key;
    struct stack_node* next;
};
typedef struct stack_node Snode;
static Snode *head, *z2, *t;

void stack_printer(Snode* head) {
    Snode* run = head->next;//skip head dummy key
    while (run->next != run) {
        printf("%c ", run->key->info);
        run = run->next;
    }
    printf("\n");
}

void stack_init() {
    head = (Snode*) malloc(sizeof *head);
    z2 = (Snode*) malloc(sizeof *z2);
    head->next = z2; head->key = 0;
    z2->next = z2;
}

void push(Node* v) {
    t = (Snode*) malloc(sizeof *t);
    t->key = v;
    t->next = head->next;
    head->next = t;
}

Node* pop() {
    Node* x;
    t = head->next;
    head->next = t->next;
    x = t->key;
    free(t);
    return x;
}


int main() {
    z = (Node*) malloc(sizeof *z);
    z->r = z;
    z->l = z;

    char c;
    for (stack_init(); scanf("%1s", &c) != EOF; ) {
        x = (Node*) malloc(sizeof *x);
        x->info = c; x->l = z; x->r = z;
        if (c == '+' || c == '*') {
            x->r = pop(); x->l = pop();
        }
        push(x);
        stack_printer(head);
    }
    printf("___________________________________________\n");
    tree_printer(pop()); printf("\n");
    return 0;
}
