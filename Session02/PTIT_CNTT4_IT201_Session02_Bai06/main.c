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
    int addIndex;
    int addValue;
    printf("\nnhap vi tri muon them: ");
    scanf("%d", &addIndex);
    printf("\nnhap gia tri muon them: ");
    scanf("%d", &addValue);
    if (addIndex >= length || addIndex < 0) {
        printf("khong hop le");
        return 0;
    }
    for (int i = length; i > addIndex; i--) {
        arr[i] = arr[i-1];
    }
    arr[addIndex] = addValue;
    length++;
    printf("mang da duoc cap nhat la: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
}