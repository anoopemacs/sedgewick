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

void select(int a[], int l, int r, int k) {
    int i = -69;
    if (r > l) {
        i = partition(a, l, r);
        // k-th smallest => k-1 elements are smaller than a[ret]
        if ((i-l) > (k-1)) select(a, l, i-1, k);
        else if ((i-l) < (k-1)) select(a, i+1, r, k-i+l-1);  // diff with text this line
    }
}

// there is a bug because anoop uses 0 based index
// author sed uses 1 based index
int main() {
    int in[] = {'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G',
                'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int size = sizeof(in) / sizeof(in[0]);
    //input ends
    int k = 0;
    select(in, 0, size-1, k); // destructive on in[]
    char ans = (char)in[k];
    printf("%d-th smallest element is %c\n", k, ans);

    //median
    select(in, 0, size-1, (size+1)/2);
    char median = (char)in[(size+1)/2];
    printf("median is %c\n", median);
    
    return 0;
}
