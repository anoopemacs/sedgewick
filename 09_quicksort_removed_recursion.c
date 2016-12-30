#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *next;
};
typedef struct node Node;

static Node *head, *z, *t;

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

int partition(int a[], int l, int r) {
    int i = l-1;
    int j = r;
    int v = a[r];
    for (;;) {
        while (a[++i] < v);
        while (a[--j] > v) if (j==l) break;
        if (i>=j) break;
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    a[r] = a[i];
    a[i] = v;
    return i;
}

int* quicksort(int a[], int size) {
    int* ret = a;
    stack_init();
    int l = 1;
    int r = size-1;

    for(;;) {
        int i = partition(a, l, r);
        
        while (r > l) {
            //push the larger subarray to stack first
            if (i-l > r-i) {
                push(l);
                push(i-1);
                l = i+1;
            } else {
                push(i+1);
                push(r);
                r = i-1;
            }
        }
        if (stack_empty_p()) break;
        r = pop(); l = pop();
    }
    
    return ret;
}

void array_printer(int* p, int size) {
    for (int i=0; i!=size; ++i) {
        printf("%3c", *(p+i));
    }
    printf("\n");
    
    for (int i=0; i!=size; ++i) {
        printf("%3d", *(p+i));
    }
    printf("\n\n");
}


int main() {
    int in[] = {'A', 'S', 'O', 'R', 'T', 'I','N', 'G',
                'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int size = sizeof(in) / sizeof(in[0]);
    array_printer(in, size);
    //input ends
    int* ans = quicksort(in, size);
    array_printer(ans, size);
    return 0;
}
