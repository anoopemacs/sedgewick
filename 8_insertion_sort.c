#include <stdio.h>
#include <limits.h>

void printer(char* p, int size) {
    for (int i=0; i!=size; ++i) {
        printf("%c ", *(p+i));
    }
    printf("\n");
}

char* insertion_sort(char a[], int size) {
    char* ret = a;
    for (int i=1; i!=size; ++i) {
        char key = a[i];
        int j;
        for (j=i-1; a[j]>key && j>-1; --j) {
            a[j+1] = a[j];
        }
        a[j+1] = key;
    }
    return ret;
}

int main() {
    char in[] = {'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int size = sizeof(in) / sizeof(in[0]);
    char* ret = insertion_sort(in, size);
    printer(ret, size);
}
