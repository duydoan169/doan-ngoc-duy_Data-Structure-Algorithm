#include <stdio.h>
int binary(int n);
int main(void) {
    int n;
    printf("nhap so nguyen duong bat ky: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("khong hop le");
    }
    binary(n);
    return 0;
}
int binary(int n) {
    if (n==0) {
        return 0;
    }
    binary(n/2);
    printf("%d", n%2);
    return 0;
}
