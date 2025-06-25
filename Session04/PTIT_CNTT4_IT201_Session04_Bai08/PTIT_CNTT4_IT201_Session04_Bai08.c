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
    int count = 0;
    printf("nhap phan tu muon tim vi tri: ");
    scanf("%d", &find);
    for (int i = 0; i < length; i++) {
        if (arr[i] == find) {
            printf("%d ", i);
            count++;
        }
    }
    if (count == 0) {
        printf("phan tu khong co trong mang");
        return 0;
    }
    return 0;
}