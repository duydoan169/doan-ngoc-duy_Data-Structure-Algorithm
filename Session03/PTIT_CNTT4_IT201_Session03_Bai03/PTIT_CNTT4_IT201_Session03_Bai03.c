#include <stdio.h>
#include <stdlib.h>

float average(float *arr,int length);
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
    float *arr = malloc((sizeof(float)) * length);
    for (int i=0; i<length; i++) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%f", &arr[i]);
    }
    printf("average = %.2f", average(arr, length));
    free(arr);
}
float average(float *arr,int length) {
    float sum = 0;
    for (int i=0; i<length; i++) {
        sum += arr[i];
    }
    return sum/length;
}