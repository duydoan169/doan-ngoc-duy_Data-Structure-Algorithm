#include <stdio.h>

int main() {
    int arr[] = {1, 2, 3, 2, 4, 2, 5, 1, 1};
    int length = sizeof(arr) / sizeof(arr[0]);
    int maxCount=0;
    int mostFrequent;
    for (int i=0; i<length; i++) {
        int count=1;
        for (int j=i+1; j<length; j++) {
            if (arr[i] == arr[j]) {
                count++;
            }
        }
        if (count>maxCount) {
            maxCount = count;
            mostFrequent = arr[i];
        }
    }
    printf("phan tu xuat hien nhieu nhat la %d", mostFrequent);
    return 0;
}
// độ phức tạp thời gian: o(n**2)
// độ phức tạp không gian: o(1)