#include <stdio.h>

int main() {
    // cach 1:
    int search;
    int count=0;
    char arr[]={1, 2, 3, 4, 7, 6, 2, 8, 9};
    int length=sizeof(arr)/sizeof(arr[0]);
    for(int i=0;i<length;i++) {
        for(int j=i+1;j<length;j++) {
            if (arr[i] == arr[j]) {
                count++;
                break;
            }
        }
    }
    if (count>0) {
        printf("co trung lap\n");
    } else {
        printf("khong trung lap\n");
    }
    // độ phức tạp thời gian: o(n**2)
    // độ phức tạp không gian: o(1)

    //cach 2:
    for (int i=0; i<length-1; i++) {
        for (int j=0; j<length-1-i; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
    for (int i=0; i<length-1; i++) {
        if (arr[i]==arr[i+1]) {
            printf("co trung lap");
            return 0;
        }
    }
    printf("khong trung lap");
    return 0;
    // độ phức tạp thời gian: o(n**2)
    // độ phức tạp không gian: o(1)
}