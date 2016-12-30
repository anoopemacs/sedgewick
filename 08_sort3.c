#include <stdio.h>
int* sort3(int* p, int N) {
    //sorts 3 numbers starting at *p
    int t;
    if (*p > *(p+1)) {
        t = *p;
        *p = *(p+1);
        *(p+1) = t;
    }
    if (*(p+1) > *(p+2)) {
        t = *(p+1);
        *(p+1) = *(p+2);
        *(p+2) = t;
    }
    if (*p > *(p+1)) {
        t = *p;
        *p = *(p+1);
        *(p+1) = t;
    }
    return p;
}

#define maxN 100

int main() {
    int N, i, a[maxN+1];
    a[0] = 0; N = 1;
    while(scanf("%d", &a[N]) != EOF) ++N;
    int* p = a;
    sort3(p+1, N);
    for (i = 1; i!=N; ++i)
        printf("%d ", a[i]);
    printf("\n");
    return 0;
}
