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

void distribution_counting_sort(int a[], int N, int M, int b[]) {
    // for any i, a[i] < M
    
    int count[M];
    for (int i=0; i!=M; ++i) count[i] = 0;
    for (int i=0; i!=N; ++i) {
        count[a[i]]++; 
    }
    //cumulative:
    for (int i=1; i!=M; ++i) {
        count[i] = count[i-1] + count[i];
    }
    
    // start from end to get stable sort behaviour
    for (int i=N-1; i!=-1; --i) {
        int x = count[a[i]];
        b[x-1] = a[i];
        count[a[i]]--;
    }
    
}

int main() {
    // special_case();
    int a[] = {'A', 'B', 'B', 'A', 'C', 'A', 'D', 'A', 'B', 'B', 'A', 'D', 'D', 'A' };
    int N = sizeof(a)/sizeof(a[0]);    
    for (int i=0; i!=N; ++i) printf("%c ", a[i]);
    printf("\n");
    // input ends
    
    int b[N]; // output will be collected here
    distribution_counting_sort(a, N, 'E', b);
    
    for (int i=0; i!=N; ++i) printf("%c ", *(b+i));
    printf("\n");
    return 0;
}


