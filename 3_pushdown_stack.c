#include <stdio.h>
#include <stdlib.h>

struct node {
    int key;
    struct node *next;
};
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
    //page 27
    /*    stack_init();
          push(1);    push(2);    push(3);    push(4);    push(5);
          stack_printer(head);
          pop(); pop();
          stack_printer(head);*/

    //page 28 part I
    //convert infix to postfix
    //input ( 5 * ( ( ( 9 + 8 ) * ( 4 * 6 ) ) + 7 ) )
    //output 5 9 8 + 4 6 * * 7 + *    
    //do algo on paper first - anoop, do division in input 
    char c;
    for (stack_init(); scanf("%1s", &c) != EOF;  ){ // %s ignores \n, whitespace in input unlike %c
        if (c == ')') printf("%1c", (char) pop());
        if (c == '+') push((int) c);
        if (c == '*') push((int) c);
        while (c >='0' && c <='9') {
            printf("%c", c);
            scanf("%1c", &c);
        }
        if (c != '(') printf(" ");
    }
    printf("\n");

    //page 28 part II
    // eval a postfix expression, eval = 2075
    /* char c; */
    /* int x; */
    /* for (stack_init(); scanf("%1s", &c) != EOF ; ) { */
    /*     x = 0; */
    /*     if (c == '+') x = pop() + pop(); */
    /*     if (c == '*') x = pop() * pop(); */
    /*     while (c >='0' && c <= '9') { */
    /*         x = 10*x + (c - '0'); */
    /*         scanf("%1c", &c); */
    /*     } */
    /*     push(x); */
    /*     stack_printer(head); */
    /* } */
    
    /* printf("\nfinal answer = %d\n", x); */
    
    return 0;
}
