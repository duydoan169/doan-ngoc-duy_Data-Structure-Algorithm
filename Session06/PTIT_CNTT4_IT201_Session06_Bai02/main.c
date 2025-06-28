#include <stdio.h>
int fibonacci(int n, int count,int fib1,int fib0);
int main(void) {
    int num;
    printf("nhap so nguyen duong bat ky: ");
    scanf("%d", &num);
    if (num<=0) {
        printf("khong hop le");
    }
    fibonacci(num, 0, 1, 0);
    return 0;
}
int fibonacci(int n, int count,int fib1,int fib0) {
    if (count == n) {
        return 0;
    }
    fibonacci(n, count+1, fib1 + fib0, fib1);
    printf("%d ", fib0);
    return 0;
}