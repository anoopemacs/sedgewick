#include <stdio.h>
#define max 25

int fibonacci(int n) {
    if (n == 0 || n == 1) return 1;
    return fibonacci(n-1) + fibonacci(n-2);
}

int fibonacci2(int n) {
    int f[max];
    f[0] = 1; f[1] = 1;
    for (int i=2; i!=max; ++i)
        f[i] = f[i-1] + f[i-2];
    return f[n];
}

int main() {
    for (int i=0; i!=20; ++i) {
        printf("%d  %d\n", fibonacci(i), fibonacci2(i));        
    }
    return 0;
}
