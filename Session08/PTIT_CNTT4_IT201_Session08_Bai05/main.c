#include <stdio.h>

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
    for (int i=1; i< length; i++) {
        int key=arr[i];
        int j;
        for (j=i-1; j>=0 && key<arr[j]; j--) {
            arr[j+1]=arr[j];
        }
        arr[j+1]=key;
    }
    for (int i = 0; i < length; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
// do phuc tap thoi gain: o(n^2)