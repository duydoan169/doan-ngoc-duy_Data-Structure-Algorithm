#include <stdio.h>
#include <stdlib.h>

int main() {
    int length;
    printf("nhap so phan tu trong mang: ");
    scanf("%d", &length);
    if (length <= 0) {
        printf("so phan tu khong hop le");
        return 0;
    }
    int *arr = (int*)malloc(length * sizeof(int));
    for (int i = 0; i < length; i++) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    int expand;
    printf("nhap so phan tu muon mo rong: ");
    scanf("%d", &expand);
    if (expand <= 0) {
        printf("so phan tu khong hop le");
        return 0;
    }
    arr = (int*)realloc(arr, (expand+length) * sizeof(int));
    for (int i = length; i < length+expand; i++) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (int i=0; i < length+expand; i++) {
        printf("%d ", arr[i]);
    }
    free(arr);
    return 0;
}
