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
    for (int i=0; i<length; i++) {
        int min = i;
        for (int j = i+1; j < length; j++) {
            if (arr[j]<arr[min]) {
                min = j;
            }
        }
        if (min != i) {
            int temp = arr[i];
            arr[i]=arr[min];
            arr[min]=temp;
        }
    }
    for (int i = 0; i < length; ++i) {
        printf("%d ", arr[i]);
    }
    return 0;
}
//do phuc tap thoi gian; o(n^2)