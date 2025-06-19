#include <stdio.h>

int main() {
    int n = 5;
    //cach 1:
    int sum = 0;
    for (int i = 0; i <= n; i++) {
        sum += i;
    }
    printf("%d\n", sum);
    // độ phức tạp thời gian: o(n)
    // độ phức tạp không gian: o(1)

    //cach 2:
    int sum2 = (n * (n + 1)) / 2;
    printf("%d\n", sum2);
    // độ phức tạp thời gian: o(1)
    // độ phức tạp không gian: o(1)
}