#include <stdio.h>
int printNum(int n);
int main(void) {
    int n;
    printf("nhap so nguyen duong bat ky: ");
    scanf("%d", &n);
    if (n<=0) {
        printf("khong hop le");
        return 0;
    }
    printNum(n);
    return 0;
}
int printNum(int n){
    if (n==0) {
        return 0;
    }
    printNum(n-1);
    printf("%d ", n);
    return 0;
}