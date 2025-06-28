#include <stdio.h>
int sumNum(int n1,int n2, int sum);
int main(void) {
    int n1, n2, sum=0;
    printf("nhap so nguyen duong thu 1: ");
    scanf("%d", &n1);
    printf("nhap so nguyen duong thu 2: ");
    scanf("%d", &n2);
    if(n1>n2 || n1<0 || n2<0) {
        printf("khong hop le");
        return 0;
    }
    printf("tong cac so tu %d den %d la: %d", n1, n2, sumNum(n1, n2, sum));
    return 0;
}
int sumNum(int n1, int n2, int sum) {
    if (n1==n2) {
        return n2 + sum;
    }
    return sumNum(n1+1, n2, sum + n1);
}