#include <stdio.h>

int main(void) {
    int length;
    do {
        printf("nhap so phan tu trong mang: ");
        scanf("%d", &length);
        if (length <= 0 || length > 100) {
            printf("\nso luong phan tu phai la so duong va nho hon 100!\n");
        }
    }while (length <= 0 || length > 100);
    int arr[length];
    for (int i = 0; i < length; i++) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    int num;
    printf("\nnhap so nguyen bat ki: ");
    scanf("%d", &num);
    for (int i = 0; i < length; i++) {
        for (int j = 0; j < length; j++) {
            if (num - arr[i] == arr[j] && arr[i] != arr[j]) {
                printf("\ncap so trong mang co tong la so vua nhap la: %d, %d", arr[i], arr[j]);
                return 0;
            }
        }
    }
    printf("khong tim thay");
}