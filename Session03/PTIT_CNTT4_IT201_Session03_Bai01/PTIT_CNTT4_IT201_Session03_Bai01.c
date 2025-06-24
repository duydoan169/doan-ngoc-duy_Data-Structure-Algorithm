#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int length;
    printf("nhap so luong phan tu trong mang: ");
    scanf("%d", &length);
    if(length<0) {
        printf("so luong phan tu khong duoc am");
        return 0;
    } else if (length==0) {
        printf("so luong phan tu phai lon hon 0");
        return 0;
    }
    int *arr = malloc((sizeof(int)) * length);
    for (int i=0; i<length; i++) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    for (int i=0; i<length; i++) {
        printf("so thu %d: %d\n", i+1, arr[i]);
    }
    free(arr);
}
