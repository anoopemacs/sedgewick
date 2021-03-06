// h sort a file
#include <stdio.h>

void printer(char* p, int size) {
    for (int i=0; i!=size; ++i) {
        printf("%3d", i+1);
    }
    printf("\n");
    for (int i=0; i!=size; ++i) {
        printf("%3c", *(p+i));
    }
    printf("\n");
}

char* shell_sort(char a[], int N) {
    char* ret = a;
    int h;
    for (h=1; (3*h+1) < N; h=3*h+1){}
    for (;h>0;h/=3){
        for (int i=h; i!=N; ++i) {
            char key = a[i];
            int j;
            for (j=i-h; j>=0 && a[j]>key; j-=h) {
                a[j+h] = a[j];
            }
            a[j+h] = key;
        }
    }
    return ret;
}

int main() {
    char in[] = {'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int size = sizeof(in) / sizeof(in[0]);
    printer(in, size);
    
    printf("\n__________________________________input ends______________________________________________________\n");
    char* ret = shell_sort(in, size);
    printf("\n__________________________________out begins______________________________________________________\n");
    printer(ret, size);
    return 0;
}






