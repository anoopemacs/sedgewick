// note 'unsigned' is a synonym for 'unsigned int' in C lang
// this file has a bug, skip for now, doubt: how to select w & m values for this algo, textbook doesnt specify that
/*
  A          01000001 
  B          01000010 
  C          01000011 
  D          01000100 
  E          01000101 
  F          01000110 
  G          01000111 
  H          01001000 
  I          01001001 
  J          01001010 
  K          01001011 
  L          01001100 
  M          01001101 
  N          01001110 
  O          01001111 
  P          01010000 
  Q          01010001 
  R          01010010 
  S          01010011 
  T          01010100 
  U          01010101 
  V          01010110 
  W          01010111 
  X          01011000 
  Y          01011001 
  Z          01011010 
*/
// since first 3 digits are same, author ignores them in diagram
/*
  A      00001 
  B      00010 
  C      00011 
  D      00100 
  E      00101 
  F      00110 
  G      00111 
  H      01000 
  I      01001 
  J      01010 
  K      01011 
  L      01100 
  M      01101 
  N      01110 
  O      01111 
  P      10000 
  Q      10001 
  R      10010 
  S      10011 
  T      10100 
  U      10101 
  V      10110 
  W      10111 
  X      11000 
  Y      11001 
  Z 	 11010 
*/

#include <stdio.h>
#include <math.h>

void printer(int* p, int size) {
    
    for (int i=0; i!=size; ++i) {
        printf("%3c", *(p+i));
    }
    printf("\n");
    
    for (int i=0; i!=size; ++i) {
        printf("%3d", *(p+i));
    }
    printf("\n\n");
}

unsigned bits(unsigned x, int k, int j) {
    // k - 0 based index from right
    // extract j bits that start at k from the right end of x in binary
    // that is extract (j+k, k] indexes from right
    return (x>>k) & ~(~0<<j);
}

unsigned getMax(unsigned a[], int N) {
    unsigned ret = a[0];
    for (int i=0; i!=N; ++i) {
	if (a[i]>ret) ret = a[i];
    }
    return ret;
}

// generalization of distribution_countint_sort:
void straight_radix_sort(int a[], int b[], int N) {
    
    int m = 5; // say 5 bits at a time
    int M = pow(2, 5);
    int w = log2(getMax(a, N)) + 1;
    
    
    for (int pass=0; pass<=m/w + 1; ++pass) {

        int count[M];
        for (int i=0; i!=M; ++i) count[i] = 0;
	
        for (int i=0; i!=N; ++i) {
            count[bits(a[i], m*pass, m)]++; 
        }
        //cumulative:
        for (int i=1; i!=M; ++i) {
            count[i] = count[i-1] + count[i];
        }
    
        for (int i=N-1; i!=0; --i) {
            int x = count[bits(a[i], m*pass, m)];
	    b[x-1] = a[i];
            count[bits(a[i], m*pass, m)]--;
        }
	
    }
}

int main() {
    
    unsigned a[] = {'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int N = sizeof(a) / sizeof(a[0]);
    printer(a, N);
    //input ends

    unsigned b[N]; // to collect output
    straight_radix_sort(a, b, N);
    
    printer(b, N);
    
    return 0;
}

