#include <stdio.h>
#define max 100
int h, t;
int queue[max+1];

void printer(int h) {
    while(h != t) {
        printf("%d ", queue[h]);
        ++h;
        if (h > max) h = 0;
    }
    printf("\n");
}

void queue_initialize() {
    h = 0;
    t = 0;
}

void put(int v) {
    queue[t] = v;
    ++t;
    if (t > max) t = 0;
}

int get() {
    int ret = queue[h];
    ++h;
    if(h > max) h = 0;
    return ret;
}

int queue_empty_p() {
    return h == t;
}

int main() {
    put(1); put(2); put(3); put(4);
    printer(h);
    get(); get();
    printer(h);
    return 0;
}
