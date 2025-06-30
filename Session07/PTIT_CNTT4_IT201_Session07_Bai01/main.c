#include <stdio.h>
void bubbleSort(int arr[], int size);
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
    bubbleSort(arr, length);
    printf("after: ");
    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }
    return 0;
}
void bubbleSort(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size - i - 1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}