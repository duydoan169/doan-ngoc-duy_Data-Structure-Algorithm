#include <stdio.h>

int main() {
    char search;
    int count=0;
    char arr[]={'a', 'b', 'e', 'c', 'c', 'a', 'a'};
    int length=sizeof(arr)/sizeof(arr[0]);
    printf("nhap phan tu muon dem so lan xuat hien: ");
    scanf("%c", &search);
    for (int i=0; i<length; i++) {
        if (arr[i]==search) {
            count++;
        }
    }
    printf("so lan xuat hien cua %c trong mang la %d", search, count);
}
// độ phức tạp thời gian: o(n)
// độ phức tạp không gian: o(1)