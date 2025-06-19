#include <stdio.h>

int printDouble(int n) {
    int i = 1;
    while (i<n) {
        printf("%d\n", i);
        i*=2;
    }
}

// dộ phức tạp thời gian: 0(log(n))