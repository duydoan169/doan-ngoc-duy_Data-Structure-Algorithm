#include <stdio.h>
int minMax(int arr[], int min, int max, int length);
int main(void) {
    int length;
    printf("nhap so phan tu trong mang: ");
    scanf("%d", &length);
    if (length <= 0) {
        printf("khong hop le");
    }
    int arr[length];
    for (int i = 0; i < length; i++) {
        printf("nhap phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    int min=arr[length-1], max=arr[length-1];
    minMax(arr, min, max, length);
    return 0;
}
int minMax(int arr[], int min, int max, int length) {
    if (length == 0) {
        printf("min: %d\n", min);
        printf("max: %d", max);
        return 0;
    }
    if (arr[length-1] > max) {
        max = arr[length-1];
    }
    if (arr[length-1] < min) {
        min = arr[length-1];
    }
    return minMax(arr, min, max, length-1);
}