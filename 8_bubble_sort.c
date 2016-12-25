#include <stdio.h>
void printer(char* p, int size) {
    for (int i=0; i!=size; ++i) {
        printf("%c ", *(p+i));
    }
    printf("\n");
}

char* bubble_sort(char a[], int size) {
    char* ret = a;
    for (int i=size-1; i>=0; --i) {
        for (int j=1; j<=i; ++j) {
            if (a[j-1] > a[j]) {
                char temp = a[j-1];
                a[j-1] = a[j];
                a[j] = temp;
            }
        }
    }
    return ret;
}

int main() {
    char in[] = {'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int size = sizeof(in) / sizeof(in[0]);
    printer(in, size);
    char* ret = bubble_sort(in, size);
    printer(ret, size);
}
