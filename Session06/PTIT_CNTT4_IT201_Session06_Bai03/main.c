#include <stdio.h>
int numSum(int num);
int main(void) {
    int num;
    printf("nhap so nguyen duong bat ky: ");
    scanf("%d", &num);
    printf("tong cac so cua %d la: %d", num, numSum(num));
    return 0;
}
int numSum(int num) {
    if (num == 0) {
        return 0;
    }
    return num%10+ numSum(num/10);
}