// note 'unsigned' is a synonym for 'unsigned int' in C lang
// this is not in 0 based index - todo conversion
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

void printer(int* p, int size) {
    ++p;
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

void radix_exchange_sort(unsigned a[], int l, int r, int b) {
    // l = left, r = right - of array [l, r]
    // b = right zero indexed begin of each element of a
    
    if (r>l && b>=0) {
	int i=l;
	int j=r;
	while (j!=i) {
	    while(bits(a[i], b, 1)==0 && i<j) ++i;
	    while(bits(a[j], b, 1)==1 && j>i) --j;
	    unsigned t = a[i];
	    a[i] = a[j];
	    a[j] = t;
	}
	if (bits(a[r], b, 1)==0) ++j;
	radix_exchange_sort(a, l, j-1, b-1);
	radix_exchange_sort(a, j, r, b-1);
    }
}

int main() {
    unsigned a[] = {'h', 'A', 'S', 'O', 'R', 'T', 'I', 'N', 'G', 'E', 'X', 'A', 'M', 'P', 'L', 'E'};
    int N = sizeof(a) / sizeof(a[0]) - 1;
    printer(a, N);
    //radix_exchange_sort(a, 1, N, 30);
    radix_exchange_sort(a, 1, N, 4);
    printer(a, N);
    return 0;
}

