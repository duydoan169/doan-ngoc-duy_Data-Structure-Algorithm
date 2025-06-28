#include <stdio.h>
int fibonacci(int num, int count, int fib0, int fib1);
int main(void) {
    int num;
    printf("nhap so nguyen duong bat ky: ");
    scanf("%d", &num);
    if (num < 0) {
        printf("khong hop le");
        return 0;
    }
    fibonacci(num, 0, 0, 1);
    return 0;
}
int fibonacci(int num, int count, int fib0, int fib1) {
    if (count == num) {
        return 0;
    }
    printf("%d ", fib0);
    fibonacci(num, count+1, fib1, fib1+fib0);
}