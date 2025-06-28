#include <stdio.h>
int sumNum(int n, int sum);
int main(void) {
    int n;
    printf("nhap so nguyen duong bat ki: ");
    scanf("%d", &n);
    if (n<=0) {
        printf("khong hop le");
        return 0;
    }
    printf("tong tu 0 den %d la: %d", n, sumNum(n, 0));
    return 0;
}
int sumNum(int n, int sum) {
    if (n==0) {
        return sum;
    }
    return sumNum(n-1, sum+n);
}