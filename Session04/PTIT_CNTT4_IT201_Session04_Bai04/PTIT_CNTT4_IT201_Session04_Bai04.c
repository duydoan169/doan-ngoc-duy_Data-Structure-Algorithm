#include <stdio.h>

int main(void) {
    int length;
    printf("nhap so phan tu trong mang: ");
    scanf("%d", &length);
    if (length <= 0) {
        printf("khong hop le");
        return 0;
    }
    int arr[length];
    for (int i = 0; i < length; i++) {
        printf("nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int find;
    printf("nhap phan tu muon tim vi tri xuat hien cuoi: ");
    scanf("%d", &find);
    for (int i = length - 1; i >= 0; i--) {
        if (arr[i] == find) {
            printf("vi tri xuat hien cuoi cua %d la %d", find, i);
            return 0;
        }
    }
    printf("khong tim thay phan tu");
    return 0;
}