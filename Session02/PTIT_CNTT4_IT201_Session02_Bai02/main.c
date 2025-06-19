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
    int count = 0;
    int find;
    for (int i = 0; i < length; i++) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\nnhap phan tu muon dem so lan xuat hien: ");
    scanf("%d", &find);
    for (int i = 0; i < length; i++) {
        if (arr[i] == find) {
            count++;
        }
    }
    printf("so lan %d xuat hien la: %d", find, count);
}