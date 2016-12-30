#include <stdio.h>
void printer(char* p, int size) {
    for (int i=0; i!=size; ++i) {
        printf("%c ", *(p+i));
    }
    printf("\n");
}

char* bubble_sort(char a[], int size) {
    char* ret = a;
    for (int j=0; j!=size-1; ++j) {
        for (int i=0; i!=size-1; ++i) {
            if (a[i] > a[i+1]) {
                char temp = a[i+1];
                a[i+1] = a[i];
                a[i] = temp;
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
