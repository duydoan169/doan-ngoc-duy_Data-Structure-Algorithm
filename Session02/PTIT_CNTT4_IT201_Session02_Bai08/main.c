#include <stdio.h>

int main(void) {
    int length;
    do {
        printf("nhap so phan tu trong mang: ");
        scanf("%d", &length);
        if (length <= 0 || length > 100) {
            printf("\nso luong phan tu phai la so duong va nho hon 100!\n");
        }
    }while (length <= 0 || length > 100);
    int arr[length];
    for (int i = 0; i < length; i++) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    printf("\ncac phan tu co gia tri lon hon phan tu dung sau la: ");
    for (int i = 0; i < length; i++) {
        if (arr[i] > arr[i+1]) {
            printf("%d", arr[i]);
        }
    }
}