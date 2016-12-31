// it is possible to implement this with input[] same as a[] i.e inplace - skip for now

// for heap 1 based index is better
#include <stdio.h>
#include <limits.h>
#define maxN 999

static int N; // static are initialized to 0
static int a[maxN];

void upheap(int k) {
    a[0] = INT_MAX;
    int v = a[k];
    while(a[k/2]<v) {
        a[k] = a[k/2];
        k = k/2;
    }
    a[k] = v;
}

void insert(int v) {
    a[++N] = v;
    //printf("%d ", N);
    upheap(N);
}

void downheap(int k) {
    int v = a[k];
    while (k <= N/2) {
        int j = 2*k;    
	if (j+1<=N && a[j]<a[j+1]) ++j;
        // now j points to larger of the 2 children
        if (a[j] <= v) break;
        a[k] = a[j];
        k = j;
    }
    a[k] = v;
}

int remove0() {
    //remove the largest
    int v = a[1];
    a[1] = a[N--];
    downheap(1);
    return v;
}

void construct(int input[], int input_size) {
    // construct a heap using input[input_size]
    N = 0;
    a[N] = INT_MAX;
    for(int i=0; i!=input_size; ++i) {
	insert(input[i]);
    }
}

int main() {
    int input[] = {'X', 'T', 'O', 'G', 'S', 'M', 'N', 'A', 'E', 'R', 'A', 'I'};
    //int input[] = {'A', 'A', 'E', 'G', 'I', 'M', 'N', 'O', 'R', 'S', 'T', 'X'};
    int input_size = sizeof(input)/sizeof(input[0]);
    for(int i=0; i!=input_size; ++i) printf("%c ", input[i]);
    
    printf("\n");
    
    //expected ans: A A E G I M N O R S T X
    construct(input, input_size);
    for(int i=input_size-1; i>=0; --i) {
	input[i] = remove0();
    }
    
    //output:
    for(int i=0; i!=input_size; ++i) printf("%c ", input[i]);
    printf("\n");
    
    return 0;
}






