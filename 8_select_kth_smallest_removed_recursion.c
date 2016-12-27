// this file is wrong, skip for now
// find the k-th smallest element
#include <stdio.h>

int partition(int a[], int l, int r) {
    int i = l-1;
    int j = r;
    int v = a[r];
    for (;;) {
        while (a[++i] < v);
        while (a[--j] > v) if (j==l) break;
        if (i>=j) break;
        int t = a[i];
        a[i] = a[j];
        a[j] = t;
    }
    a[r] = a[i];
    a[i] = v;
    return i;
}

void select(int a[], int N, int k) {
    int l = 0;
    int r = N-1;
    
    int i, j, v, t;
    while (r > l) {
        v = a[r];
        i = l-1; // sentinel
        j = r;
        for(;;) {
            while (a[++i] < v);
            while (a[--j] > v);
            if (i >= j) break;
            t = a[i];
            a[i] = a[r];
            a[r] = t;
        }
        a[r] = a[i];
        a[i] = v;
        if (i >= k) r = i-1;
        if (i <= k) l = i+1;
    }
}

// there is a bug because anoop uses 0 based index
// author sed uses 1 based index
int main() {
    int in[] = {'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G',
                'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int size = sizeof(in) / sizeof(in[0]);
    //input ends
    
    int k = 2;
    select(in, size, k); // destructive on in[]
    char ans = (char)in[k];
    printf("%d-th smallest element is %c\n", k, ans);

    //median
    select(in, size, (size+1)/2);
    char median = (char)in[(size+1)/2];
    printf("median is %c\n", median);
    
    return 0;
}
