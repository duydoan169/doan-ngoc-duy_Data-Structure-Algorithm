#include <stdio.h>
int main() {
    int n;
    do {
        printf("=====MENU=====\n");
        printf("1. VISIT url\n");
        printf("2. BACKWARD\n");
        printf("3. FORWARD\n");
        printf("4. CURRENT\n");
        printf("5. EXIT\n");
        printf("==============\n");
        printf("nhap lua chon cua ban: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                break;
            case 5:
                break;
            default:
                printf("khong hop le\n");
        }
        printf("da thoat chuong trinh!");
    }while (n!=5);
}