#include <stdio.h>

void mergeSort(int arr[], int start, int end);
void merge(int arr[], int start, int mid, int end);

int main(void) {
    int length;
    printf("nhap do dai mang: ");
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

    mergeSort(arr, 0, length - 1);

    for (int i = 0; i < length; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}

void mergeSort(int arr[], int start, int end) {
    if (start >= end) return;

    int mid = (start + end) / 2;
    mergeSort(arr, start, mid);
    mergeSort(arr, mid + 1, end);
    merge(arr, start, mid, end);
}

void merge(int arr[], int start, int mid, int end) {
    int leftSize = mid - start + 1;
    int rightSize = end - mid;

    int left[leftSize], right[rightSize];

    for (int i = 0; i < leftSize; i++) {
        left[i] = arr[start + i];
    }
    for (int i = 0; i < rightSize; i++) {
        right[i] = arr[mid + 1 + i];
    }

    int i = 0, j = 0, k = start;
    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k++] = left[i++];
        } else {
            arr[k++] = right[j++];
        }
    }

    while (i < leftSize) {
        arr[k++] = left[i++];
    }
    while (j < rightSize) {
        arr[k++] = right[j++];
    }
}
//do phuc tap thoi gian: o(nlogn)