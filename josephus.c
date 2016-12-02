#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node* next;
};
typedef struct node Node;

void circular_list_printer(Node* x) {
    Node* run = x;
    while(run->next != x) {
        printf("%d ", run->key);
        run = run->next;
    }
    printf("%d\n", run->key);
}

int main() {
    int N, M; // N-people, M-th suicide
    scanf("%d %d", &N, &M);
    Node* t;
    t = (Node*) malloc(sizeof *t);
    Node* x = t; // x stores the starting point of the list
    t->key = 1;
    for (int i=2; i!=N+1; ++i) {
        t->next = (Node*) malloc(sizeof *t);
        t = t->next;
        t->key = i;
    }
    t->next = x;
    circular_list_printer(x);
    
    //suicide:
    t = x;
    while(t->next != t) {
        for (int i=1; i!=M-1; ++i) {
            t = t->next;
        }
        Node* delete = t->next;
        printf("%d ", delete->key);        
        t->next = delete->next;
        free(delete);
        t = t->next;
    }
    printf("%d\n", t->key);
    
    return 0;
}
