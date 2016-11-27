//euclid's algorithm for gcd
#include <stdio.h>

int gcd (int u, int v) {
    int t;
    while (u > 0) {
        if (u < v) { t = u; u = v; v = t;}
         //        printf("u = %d, v = %d\n", u, v);        
        u = u-v;
    }
    //printf("u = %d, v = %d\n", u, v);
    return v;
}

int gcd2 (int u, int v) {
    int t;
    while (u > 0) {
        if (u < v) { t = u; u = v; v = t;}
        //printf("u = %d, v = %d\n", u, v);        
        //printf("------------------------------------------------------------------\n");
        u = u%v;
    }
    //printf("u = %d, v = %d\n", u, v);
    return v;
}

int main() {
    int x, y;
    while (scanf("%d %d", &x, &y) != EOF)
        if (x>0 && y>0)
            printf("%6d %6d %6d %6d\n", x, y, gcd(x, y), gcd2(x, y));
    
    return 0;
}
