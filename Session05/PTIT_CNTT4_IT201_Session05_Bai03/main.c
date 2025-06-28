#include <stdio.h>
int factorial(int n);
int main(void) {
    int n;
    printf("nhap so nguyen duong bat ki: ");
    scanf("%d", &n);
    if (n<0) {
        printf("khong hop le");
        return 0;
    }
    printf("luy thua cua %d la: %d", n, factorial(n));
    return 0;
}
int factorial(int n) {
    if (n==0 || n==1) {
        return 1;
    }
    return n*factorial(n-1);
}