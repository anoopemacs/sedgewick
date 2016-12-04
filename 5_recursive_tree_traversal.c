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

//stack from ch3 modified to store pointers
//stack is used to temporarily store scanf input
struct stack_node {
    Node* key;
    struct stack_node* next;
};
typedef struct stack_node Snode;
Snode *head, *z1, *t;

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
    z1 = (Snode*) malloc(sizeof *z1);
    head->next = z1; head->key = 0;
    z1->next = z1;
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

int stack_empty_p() {
    return head->next == z1;
}
//stack ends


void preorder(Node* r) {
    printf("%c ", r->info);
    if (r->l != z) preorder(r->l);
    if (r->r != z) preorder(r->r);    
}

void postorder(Node* r) {
    if (r->l != z) postorder(r->l);
    if (r->r != z) postorder(r->r);
    printf("%c ", r->info);
}

void inorder(Node* r) {
    if (r->l != z) inorder(r->l);
    printf("%c ", r->info);
    if (r->r != z) inorder(r->r);
}

int main() {
    //note convention:
    //stack = head, z2, t
    //tree = h, z, x
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
        //        stack_printer(head);
    }
    printf("_________________now stack contains the tree_______%d___________________\n", stack_empty_p());
    Node* root = pop();
    
    printf("\n**************preorder starts*******************\n");    
    preorder(root);
    printf("\n**************preorder ends*******************\n");    

    printf("\n**************postorder starts*******************\n");
    postorder(root);
    printf("\n**************postorder ends*******************\n");
    
    printf("\n**************inorder starts*******************\n");
    inorder(root);
    printf("\n**************inorder ends*******************\n");
    
    return 0;
} 
