// traversal w/o using recursion
// file contains 2 stacks, 1 queue, Node type, Snode type, Qnode type structs

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

//2nd stack for post order
Snode *head2, *z2, *t2;
void stack_init2() {
    head2 = (Snode*) malloc(sizeof *head2);
    z2 = (Snode*) malloc(sizeof *z2);
    head2->next = z2; head2->key = 0;
    z2->next = z2;
}

void push2(Node* v) {
    t2 = (Snode*) malloc(sizeof *t2);
    t2->key = v;
    t2->next = head2->next;
    head2->next = t2;
}

Node* pop2() {
    Node* x;
    t2 = head2->next;
    head2->next = t2->next;
    x = t2->key;
    free(t2);
    return x;
}

int stack_empty_p2() {
    return head2->next == z2;
}
//2nd stack ends

//queue from ch3
struct queue_node {
    Node* key;
    struct queue_node* next;
};
typedef struct queue_node Qnode;

Qnode* qh; Qnode* qz; Qnode* qt;

void queue_printer(Qnode* qh) {
    Qnode* qr = qh->next;
    while(qr != qz) {
        printf("%c ", qr->key->info);
        qr = qr->next;
    }
    printf("\n");
}

int queue_empty_p() {
    return (qh->next == qz);
}

void queue_initialize() {
    qh = (Qnode*) malloc(sizeof *qh);
    qz = (Qnode*) malloc(sizeof *qz);    
    qh->next = qz; qz->next = qz;
}

void put(Node* v) {
    qt = (Qnode*) malloc(sizeof *qt);
    qt->key = v; qt->next = qh->next;
    qh->next = qt;
}

Node* get() {
    Node* ret;
    Qnode* qr = qh;
    if (queue_empty_p()) {
        printf("empty queue get called error");
        return ret;
    }
    while (qr->next->next != qz) qr = qr->next;//last but one
    Qnode* delete = qr->next;
    qr->next = qz;
    ret = delete->key;
    
    free(delete);
    return ret;
}

//queue ends

void preorder(Node* root) {
    printf("**************preorder starts*******************\n");
    Node* x;
    printf("inside, stack_empty=%d\n", stack_empty_p());
    push(root);
    while(!stack_empty_p()) {
        x = pop();
        printf("%c ", x->info);
        if (x->r != z) push(x->r);
        if (x->l != z) push(x->l);
        //stack_printer(head);//turn off above printf when looking at stack printer
    }
    printf("\n**************preorder ends*******************\n");
}

void postorder(Node* root) {
    printf("**************postorder starts*******************\n");
    Node* r = root;
    stack_init(); stack_init2();
    printf("stack_empty_p = %d, stack_empty_p2 = %d\n", stack_empty_p(), stack_empty_p2());    
    push(r);
    while(!stack_empty_p()) {
        r = pop();
        push2(r);
        if(r->l != z) push(r->l);
        if(r->r != z) push(r->r);
    }
    stack_printer(head2);    
    printf("**************postorder ends*******************\n");
}

void levelorder(Node* root) {
    printf("**************levelorder starts*******************\n");
    Node* r = root;
    printf("q empty=%d\n", queue_empty_p());
    put(r);
    
    while(!queue_empty_p()) {
        r = get();
        printf("%c ", r->info);
        if(r->l != z) put(r->l);
        if(r->r != z) put(r->r);
        //    queue_printer(qh);                
    }
    
    printf("\n**************levelorder ends*******************\n");
}

void inorder(Node* root) {
    //see ch5
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
        stack_printer(head);
    }
    printf("_________________now stack contains the tree_______%d___________________\n", stack_empty_p());
    Node* root = pop();
    preorder(root);
    //inorder(root); //see ch5
    queue_initialize();
    levelorder(root);
    postorder(root);
    inorder(root);
    return 0;
}
