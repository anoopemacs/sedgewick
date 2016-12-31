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
    int j = 2*k;
    int v = a[k];
    while (k <= N/2) {
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

int replace(int v) {
    // put v into heap, pop largest out
    a[0] = v;
    downheap(0);
    // note special case: downheap(0) works by considering a[0]'s children to be a[2*0] & a[2*0+1]
    return a[0];
}

void delete(int k) {
    int old0 = a[k];
    a[k] = a[N--];
    if (a[k] <= old0) downheap(k);
    else upheap(k);
}

void priority_change(int k, int new0) {
    // value of a[k] changed to new0
    int old0 = a[k];
    a[k] = new0;
    if (new0<=old0) downheap(k);
    else upheap(k);
}

int main() {
    //initial heap cheat:
    int input[] = {'X', 'T', 'O', 'G', 'S', 'M', 'N', 'A', 'E', 'R', 'A', 'I'};
    for(int i=0; i!=sizeof(input)/sizeof(input[0]); ++i) a[++N] = input[i];
    
    for(int i=1; i<=N; ++i) printf("%c ", a[i]);
    printf("\n");
    
    insert('P');
    for(int i=1; i<=N; ++i) printf("%c ", a[i]);
    printf("\n");
    
    return 0;
}






