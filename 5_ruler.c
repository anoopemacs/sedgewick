#include <stdio.h>
#define max_x 65
int ht[max_x];

void print_ruler() {
    for (int i=1; i!=max_x; ++i) {
        int hi = ht[i];
        printf("%3d", hi);
    }
    printf("\n");
}

void print_ruler_visual() {//destructive
    int sum = 0;
    for (int i=0; i!=max_x; ++i) {
        sum += ht[i];
    }
    if (sum != 0) {
        for (int i=0; i!=max_x; ++i) {
            if (ht[i] > 0) {
                printf("|");
                ht[i] = ht[i] - 1;
            } else {
                printf(" ");
            }
        }
        printf("\n");
        print_ruler_visual();
    }
}

int mark(int x, int h) {
    ht[x] = h;    
}

void rule(int l, int r, int h) {
    int m = (r + l) / 2;
    if (h > 0) {
        mark(m, h);
        rule(l, m, h-1);
        rule(m, r, h-1);
    }
}

void binary_printer (int i) {
    if (i > 1)
        binary_printer(i/2);
    printf("%d", i%2);
}

void rule2(int l, int r, int h) { //?
    for (int i=1, j=1; i!=h+1; ++i) {
        //printf("j = %d, l+r /j = %d\n", j, (l+r)/ j);
        for (int t=0; t!=(l+r)/j; ++t) {
            mark(l+j+t*(j+j), i);
        }
        j += j;
    }
}

int main() {
    for (int i=1; i!=max_x; ++i) {ht[i] = 0;} //initialize, 1 based index
    //ht[i] = height at point i
    
    for (int i=1; i!=max_x; ++i) {printf("%3d", i);}
    printf("\n");
    rule(0, 64, 6);
    print_ruler();
    print_ruler_visual();

    //iterative version, num of trailing zeros in binary format = height at point
    /* for (int i=1; i!=max_x; ++i) { */
    /*     printf("i = %d, binary = ", i); */
    /*     binary_printer(i); */
    /*     printf("\n"); */
    /* } */

    //level order traversal
    for (int i=1; i!=max_x; ++i) {ht[i] = 0;} //re-initialize, 1 based index
    print_ruler();
    rule2(0, 64, 6);
    print_ruler();
    print_ruler_visual();
    
    return 0;
}
