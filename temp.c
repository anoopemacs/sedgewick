#include <stdio.h>
void printer(char* p, int size) {
    for (int i=0; i!=size; ++i) {
        printf("%c ", *(p+i));
    }
    printf("\n");
}

char* selection_sort(char a[], int size) {
    
}

int main() {
    char in[] = {'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int size = sizeof(in) / sizeof(in[0]);
    selection_sort(in, size);
    printer(in, size);
}
