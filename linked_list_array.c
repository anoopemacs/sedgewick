#include <stdio.h>
#define max 100

int key[max+2], next[max+2];
int h, z, x;

void list_initialize() {
    h = 0;
    z = 1;
    next[h] = z;
    next[z] = z;
    x = 2;
}

void list_printer(int h) {
    int r = h;
    while(next[r] != z) {
        printf("%c ", (char) key[next[r]]);
        r = next[r];
    }
    printf("\n");
}

int insert_after(int v, int t) {
    key[x] = v;
    next[x] = next[t];
    next[t] = x;
    return ++x;
}

void delete_next(int t) {
    next[t] = next[next[t]];
}

int main() {
    list_initialize();
    insert_after((int) 'S', h);    
    insert_after((int) 'L', h);    
    insert_after((int) 'A', h);
    insert_after((int) 'I', next[next[h]]);
    insert_after((int) 'T', next[next[next[next[h]]]]);
    list_printer(h);

    printf("\n");
    for (int i=0; i!=x; ++i) {
        printf("%c  %d\n", (char) key[i], next[i]);
    }
    return 0;
}
