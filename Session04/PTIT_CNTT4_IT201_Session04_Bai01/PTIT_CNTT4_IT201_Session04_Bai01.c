#include <stdio.h>

int main(){
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
    printf("nhap gia tri muon tim: ");
    scanf("%d", &find);
    for (int i = 0; i < length; i++) {
        if (arr[i] == find) {
            printf("phan tu %d xuat hien tai vi tri %d", find, i+1);
            return 0;
        }
    }
    printf("khong tim thay phan tu");
    return 0;
}