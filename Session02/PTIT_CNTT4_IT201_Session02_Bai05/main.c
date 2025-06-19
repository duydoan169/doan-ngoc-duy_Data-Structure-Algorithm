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
    int deleteIndex;
    printf("\nnhap vi tri muon xoa: ");
    scanf("%d", &deleteIndex);
    if (deleteIndex >= length || deleteIndex < 0) {
        printf("khong hop le");
        return 0;
    }
    for (int i = deleteIndex; i < length; i++) {
        arr[i] = arr[i + 1];
    }
    length--;
    printf("\nmang da duoc cap nhat la: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}