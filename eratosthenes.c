//eratosthenes all primes below 1000
#define N 1000
#include <stdio.h>
int main() {
    int i, j, a[N+1];
    //a[i] = 1  means i is prime, a[0] is unused here
    for (a[1]=0, i=2; i!=N+1; ++i) a[i] = 1;
    for (i=2; i!=N/2; ++i)// i!=N+1 also works
        for (j=2; j<=N/i; ++j)
            a[i*j] = 0;

    for (int i=1; i<=N; ++i) {
        if(a[i]) printf("%4d", i);
    }
    printf("\n");
    return 0;
}
