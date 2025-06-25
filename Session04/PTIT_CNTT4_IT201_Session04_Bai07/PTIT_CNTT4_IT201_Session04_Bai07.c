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
    int count=0;
    for (int i = 0; i < length/2; i++) {
        if (arr[i] == arr[length-1-i]) {
            printf("Cap doi xung: (%d, %d)\n", arr[i], arr[length-1-i]);
            count++;
        }
    }
    if (count == 0) {
        printf("khong co phan tu doi xung");
    }
    return 0;
}