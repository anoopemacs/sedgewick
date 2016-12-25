#include <stdio.h>

void printer(char* p, int size) {
    for (int i=0; i!=size; ++i) {
        printf("%2c ", *(p+i));
    }
    printf("\n");
}

char* insertion_sort(char a[], int p[], int size) {
    char* ret = a;
    for (int i=0; i!=size-1; ++i) {
        int j = i+1;
        char key = p[j];
        while (j!=0 && a[p[j-1]]>a[key]) {
            p[j] = p[j-1];
            --j;
        }
        p[j] = key;
    }
    return ret;
}

void insitu(char a[], int p[], int size) {
    for (int i=0; i!=size; ++i) {
        if (p[i] != i) {
            char t = a[i];
            int k = i;
            int j;
            do {
                j = k;
                a[j] = a[p[j]];
                k = p[j];
                p[j] = j;
            } while (k != i);
            a[j] = t;
        }
    }
}

int main() {
    char a[] = {'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int p[] = { 0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14 };
    int size = sizeof(a) / sizeof(a[0]);
    
    for (int i=0; i!=size; ++i) printf("%2d ", p[i]+1);
    printf("\n");
    printer(a, size);
    printf("\n");
    
    char* ret = insertion_sort(a, p, size);
    for (int i=0; i!=size; ++i) printf("%2d ", p[i]+1);
    printf("\n");
    for (int i=0; i!=size; ++i) printf("%2c ", a[p[i]]);
    printf("\n\n");
    
    printer(a, size);
    insitu(a, p, size);
    printer(a, size);
    
    return 0;
}
