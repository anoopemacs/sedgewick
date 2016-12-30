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
    int i, j, h, v;
    for (h=1; h<=N/9;h=3*h+1){}
    //printf("%d\n", h);
    
    for (; h>0; h/=3) {
        for (i = h+1; i!=N; ++i) {
            printf("anoop%d\n", i);
            v = a[i]; j =i ;
            while (j>h && a[j-h]>v) {
                a[j] = a[j-h];
                j -= h;
                a[j] = v;
            }
        }
        printer(a, N);        
    }
    return ret;
}

int main() {
    char in[] = {'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int size = sizeof(in) / sizeof(in[0]);
    printer(in, size);
    
    printf("\n__________________________________input ends______________________________________________________\n");
    char* ret = shell_sort(in, size);
    //printer(ret, size);
    return 0;
}






