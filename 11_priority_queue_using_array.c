// other possibilities to try:
// 1. using unordered list  , 2. using ordered list

#include <stdio.h>
#define maxN 69

//a[0] && a[N+1] are reserved for sentinels
// static means inaccessible from outside?
// (0, N+1) or [1, N]

static int a[maxN+1], N;

void construct(int b[], int M) {
    for(N=1; N<=M; ++N) {
	a[N] = b[N];
    }
}

void insert(int v) {
    a[++N] = v;
}

int remove() {
    int max=1;
    for (int j=2; j<=N; ++j) {
	if(a[j]>a[max]) max=j;
    }
    int ret = a[max];
    a[max] = a[N--];
    return ret;
}

void replace(int new0, int old0) {
    for (int i=1; i<=N; ++i) {
	if(a[i]==old0) {
	    a[i] = new0;
	    break;
	}
    }
}

void change(int index0, int newValue) {
    // change a[index0] to newValue
    a[index0] = newValue;
}

void delete(int index0) {
    // delete a[index0]
    a[index0] = a[N--];
}

int main() {
    
    return 0;
}
