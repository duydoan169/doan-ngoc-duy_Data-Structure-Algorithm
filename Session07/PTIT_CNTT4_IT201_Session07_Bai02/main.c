#include <stdio.h>
void selectionSort(int arr[], int length);
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
    printf("before: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    selectionSort(arr, length);
    printf("after: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
void selectionSort(int arr[], int length) {
    for (int i=0; i<length-1; i++) {
        int minIndex=i;
        for (int j=i; j<length; j++) {
            if (arr[j] < arr[minIndex]) {
                minIndex=j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}