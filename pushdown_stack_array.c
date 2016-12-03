#include <stdio.h>
#define max 100
int stack[max+1];
int x;

void printer() {
    for (int i = 0; i != x; ++i) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

void stack_initialize() {
    x = 0;
}

void push(int v) {
    stack[x++] = v;
}

int pop() {
    --x;
    return stack[x];
}

int stack_empty_p() {
    return !x;
}

int main() {
    push(1); push(2); push(3);
    printer();
    printf("pop = %d\n", pop());
    printer();
    return 0;
}
