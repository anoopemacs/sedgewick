#include <stdio.h>

int special_case() {
    char in[] = {8, 9, 0, 7, 4, 3, 2, 5, 6, 1 };
    char temp[10];
    int size = sizeof(in) / sizeof(in[0]);
    for(int i=0; i!=size; ++i) {
        temp[in[i]] = in[i];
    }
    for (int i=0; i!=size; ++i) {
        printf("%d ", temp[i]);
    }
    // now temp array contains sorted array
    return 0;
}

int ci(char c) {
    // char to int conversion custom
    return (int) (c - 'A');
}

char ic(int i) {
    // int to char custom
    return (char) ((int) 'A' + i);
}

char* distribution_counting_sort(char a[], int N, char M) {
    char* ret=a;
    printf("N=%d M=%c, ci(M)=%d\n", N, M, ci(M));
    int count[M];
    for (int i=0; i!=ci(M); ++i) count[i] = 0;
    for (int i=0; i!=N; ++i) {
        int ai = ci(a[i]);
        count[ai]++; 
    }
    //cumulative:
    for (int i=1; i!=ci(M); ++i) {
        count[i] = count[i-1] + count[i];
    }
    
    char b[N];
    ret = b;
    for (int i=0; i!=N; ++i) {
        int ai = ci(a[i]);
        int x = count[ai];
        b[x-1] = a[i];
        count[ai]--;
    }
    
    return ret;
}

int main() {
    //special_case();
    char in[] = {'A', 'B', 'B', 'A', 'C', 'A', 'D', 'A', 'B', 'B', 'A', 'D', 'D', 'A' };
    int N = sizeof(in)/sizeof(in[0]);    
    for (int i=0; i!=N; ++i) printf("%c ", in[i]);
    printf("\n");
    //input ends
    
    char M = 'E';
    int m = ci(M);
    
    char* ans = distribution_counting_sort(in, N, M);
    
    for (int i=0; i!=N; ++i) printf("%c ", *(ans+i));
    return 0;
}
