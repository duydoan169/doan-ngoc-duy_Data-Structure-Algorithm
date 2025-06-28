#include <stdio.h>
int arrSum(int arr[], int length, int i, int sum);
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
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("tong cac phan tu trong mang la: %d", arrSum(arr, length, 0, 0));
    return 0;
}
int arrSum(int arr[], int length, int i, int sum) {
    if (i == length) {
        return sum;
    }
    return arrSum(arr, length, i+1, sum + arr[i]);
}