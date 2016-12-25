#include <stdio.h>
void printer(char* p, int size) {
    for (int i=0; i!=size; ++i) {
        printf("%c ", *(p+i));
    }
    printf("\n");
}

char* selection_sort(char a[], int size) {
    char* ret = a;
    for (int i=1; i != size-1; ++i) {
        int min = i;
        for (int j=i; j != size; ++j) {
            if (a[j] < a[min]) {
                min = j;
            }
        }
        char temp = a[i];
        a[i] = a[min];
        a[min] = temp;
        printer(a, size);
    }
    return ret;
}

int main() {
    char in[] = {'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int size = sizeof(in) / sizeof(in[0]);
    selection_sort(in, size);
}
