#include <stdio.h>
#include <string.h>

int gcd (int u, int v) {
    int t;
    while (u > 0) {
        printf("u = %d, v = %d\n", u, v);
        if (u < v)
        { t = u; u = v; v = t;}
        u = u-v;
    }
    return v;
}

int main() {
    printf("hello");
    
    return 0;
}
