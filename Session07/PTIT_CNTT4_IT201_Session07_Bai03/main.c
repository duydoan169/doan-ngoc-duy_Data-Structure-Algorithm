#include <stdio.h>
void insertionSort(int arr[], int length);
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
    insertionSort(arr, length);
    printf("after: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
void insertionSort(int arr[], int length) {
    for (int i = 1; i < length; i++) {
        int key = arr[i];
        int j = i-1;
        while (j>=0 && key < arr[j]) {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}