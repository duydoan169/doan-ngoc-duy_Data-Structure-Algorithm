#include <stdio.h>

int main() {
    int length;
    do {
        printf("nhap so phan tu trong mang: ");
        scanf("%d", &length);
        if (length <= 0 || length > 100) {
            printf("\nso luong phan tu phai la so duong va nho hon 100!\n");
        }
    }while (length <= 0 || length > 100);
    int arr[length];
    int max = 0;
    for (int i = 0; i < length; i++) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    printf("phan tu lon nhat trong mang la: %d", max);
}