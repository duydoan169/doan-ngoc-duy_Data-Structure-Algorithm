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
    for (int i = 0; i < length-1; i++) {
        for (int j = 0; j < length-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    int find;
    printf("nhap phan tu muon tim: ");
    scanf("%d", &find);
    int start=0;
    int end=length-1;
    while (start<=end) {
        int mid = start + (end-start)/2;
        if (find==arr[mid]) {
            printf("phan tu co ton tai trong mang");
            return 0;
        } else if (find>arr[mid]) {
           start=mid+1;
        } else if (find<arr[mid]) {
            end=mid-1;
        }
    }
    printf("phan tu khong ton tai trong mang");
    return 0;
}