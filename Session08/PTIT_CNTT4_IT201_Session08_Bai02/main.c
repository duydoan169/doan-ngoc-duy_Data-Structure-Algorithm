#include <stdio.h>
int binarySearch(int arr[], int find, int left, int right);
int main(void) {
    int length;
    printf("nhap do dai mang: ");
    scanf("%d", &length);
    if (length<=0 || length>=1000) {
        printf("khong hop le");
        return 0;
    }
    int arr[length];
    for (int i = 0; i < length; i++) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (int i=1; i<length; i++) {
        int key = arr[i];
        int j;
        for (j=i-1; j>=0 && key < arr[j]; j--) {
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
    int find;
    printf("nhap phan tu muon tim: ");
    scanf("%d", &find);
    int result = binarySearch(arr, find, 0, length-1);
    if (result != -1) {
        printf("vi tri %d", result+1);
    }else {
        printf("khong ton tai phan tu");
    }
    return 0;
}
int binarySearch(int arr[], int find, int left, int right) {
    if (left>right) {
        return -1;
    }
    int mid = (left + right)/2;

    if (arr[mid]==find) {
        return mid;
    } else if (find<arr[mid]) {
        return binarySearch(arr, find, left, mid-1);
    } else {
        return binarySearch(arr, find, mid+1, right);
    }
}
// do phuc tap thoi gian: o(n^2)