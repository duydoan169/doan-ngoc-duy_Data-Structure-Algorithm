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
    int find;
    int count=0;
    printf("nhap phan tu muon tim: ");
    scanf("%d", &find);
    for (int i=0; i < length; i++) {
        if (arr[i]==find) {
            printf("vi tri thu %d\n", i+1);
            count++;
        }
    }
    if (count==0) {
        printf("khong ton tai phan tu");
    }

    return 0;
}
// do phuc tap thoi gian: o(n)