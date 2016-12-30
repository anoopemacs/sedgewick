#include <stdio.h>
void printer(int* p, int size) {
    for (int i=0; i!=size; ++i) {
        printf("%3c", *(p+i));
    }
    printf("\n");
    
    for (int i=0; i!=size; ++i) {
        printf("%3d", *(p+i));
    }
    printf("\n\n");
}

int* quicksort(int a[], int l, int r) {
    int* ret = a;
    // [i, j] moving indices
    int i, j, v, t;
    // t = temp, v = pivot value

    if (r > l) {
        v = a[r];
        i = l-1;
        j = r;
        for (;;) {
            while (a[++i] < v);
            while(a[--j] > v) if (j==l) break;
            if (i >= j) break;
            t = a[i];
            a[i] = a[j];
            a[j] = t;
        }
        a[r] = a[i];
        a[i] = v;
        quicksort(a, l, i-1);
        quicksort(a, i+1, r);
    }
    return ret;
}

int main() {
    int in[] = {'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E', '-'};
    int size = sizeof(in) / sizeof(in[0]);
    printer(in, size);
    int* ans = quicksort(in, 0, size-1);
    printer(ans, size);
    return 0;
}
