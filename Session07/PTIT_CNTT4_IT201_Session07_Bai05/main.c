#include <stdio.h>
int partition(int arr[], int start, int end);
void quickSort(int arr[], int start, int end);
int main(void) {
    int length;
    printf("nhap do dai mang: ");
    scanf("%d", &length);
    if (length<=0) {
        printf("khong hop le");
        return 0;
    }
    int arr[length];
    for (int i = 0; i < length; i++) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    quickSort(arr, 0, length-1);
    for (int i = 0; i < length; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
int partition(int arr[], int start, int end) {
    int pivotValue=arr[end];
    int i=start;
    for (int j=start; j<end; j++) {
        if (arr[j]<pivotValue) {
            int temp = arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
            i++;
        }
    }
    int temp = arr[i];
    arr[i]=arr[end];
    arr[end]=temp;
    return i;
}
void quickSort(int arr[], int start, int end) {
    if (start>=end) {
        return;
    }
    int pivotIndex = partition(arr, start, end);
    quickSort(arr, start, pivotIndex-1);
    quickSort(arr, pivotIndex+1, end);
}