#include <stdio.h>

int main() {
    int arr[] = {4, 5, 2 , 1, 3, 6};
    int length = sizeof(arr) / sizeof(arr[0]);
    for (int i=0; i<length-1; i++) {
        for (int j=0; j<length-i-1; j++) {
            if (arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
            }
        }
    }
}
// độ phức tạp thời gian: o(n**2)
// độ phức tạp không gian: o(1)