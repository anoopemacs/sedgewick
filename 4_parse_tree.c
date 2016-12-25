// 5*[{(9+8) * (4*6)}+7] = 2075
// (* 5 (+ (* (+ 9 8) (* 4 6)) 7))
// input is in post order notation

#include <stdio.h>
#include <stdlib.h>

struct tree_node {
    struct tree_node* l;
    struct tree_node* r;
    char key;
};
typedef struct tree_node Tnode;
// h_tree is not necessary
Tnode* z_tree;
Tnode* t_tree;

void tree_initialize() {
    z_tree = (Tnode*) malloc(sizeof *z_tree);
    z_tree->l = z_tree;    
    z_tree->r = z_tree;    
}

void tree_printer2(Tnode* root) {
    Tnode* t = root;
    
    if (t != z_tree){
        printf("%c ", t->key);
        tree_printer2(t->l);
        tree_printer2(t->r);
    } else {
        printf(". ");
    }
    return;
}


void tree_printer(Tnode* root) {
    Tnode* t_tree = root;    
    printf("%c ", t_tree->key);
    
    if (root->l != z_tree) tree_printer(t_tree->l);
    if (root->r != z_tree) tree_printer(t_tree->r);
    
}

struct stack_node {
    Tnode* info;
    struct stack_node* next;
};
typedef struct stack_node Snode;
Snode* h_stack;
Snode* z_stack;
Snode* t_stack;

void stack_initialize() {
    h_stack = (Snode*) malloc(sizeof *h_stack);    
    z_stack = (Snode*) malloc(sizeof *z_stack);    
    h_stack->next = z_stack;
    z_stack->next = z_stack;
}

void stack_printer(Snode* h) {
    Snode* r = h->next;
    while (r != z_stack) {
        printf("%c ", r->info->key);
        r = r->next;
    }
    printf("\n");
}

void push(Tnode* info) {
    t_stack = (Snode*) malloc(sizeof *t_stack);
    t_stack->info = info;
    t_stack->next = h_stack->next;
    h_stack->next = t_stack;
}

Tnode* pop() {
    Tnode* ret;
    t_stack = h_stack->next;
    ret = t_stack->info;
    h_stack->next = t_stack->next;
    free(t_stack);
    return ret;
}

int main() {
    stack_initialize();
    tree_initialize();
    
    char c;
    for (; scanf("%1s", &c) != EOF; ) {
        t_tree = (Tnode*) malloc(sizeof *t_tree);
        t_tree->key = c;
        t_tree->r = z_tree;
        t_tree->l = z_tree;
        if (c == '*' || c == '+') {
            t_tree->r = pop();
            t_tree->l = pop();
        }
        push(t_tree);
    }
    printf("\n");    
    stack_printer(h_stack);
    printf("----------------------------------above is stack-----------------------------------------------------------------\n");
    Tnode* root = pop();
    tree_printer(root);
    printf("\n---------------------------------second tree printer:-----------------------------------------------------------------\n");
    tree_printer2(root);
    return 0;
}
