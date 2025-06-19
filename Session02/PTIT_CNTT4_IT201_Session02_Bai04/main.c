#include <stdio.h>

int main(void) {
    int length;
    int arr[100];
    do {
        printf("nhap so phan tu trong mang: ");
        scanf("%d", &length);
        if (length <= 0 || length > 100) {
            printf("\nso luong phan tu phai la so duong va nho hon 100!\n");
        }
    }while (length <= 0 || length > 100);
    for (int i = 0; i < length; i++) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    int fixIndex;
    int fixValue;
    printf("nhap vi tri muon sua: ");
    scanf("%d", &fixIndex);
    printf("nhap gia tri sua: ");
    scanf("%d", &fixValue);
    if (fixIndex >= length) {
        arr[length-1] = fixValue;
    } else if (fixIndex < 0) {
        arr[0] = fixValue;
    } else {
        arr[fixIndex] = fixValue;
    }
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}