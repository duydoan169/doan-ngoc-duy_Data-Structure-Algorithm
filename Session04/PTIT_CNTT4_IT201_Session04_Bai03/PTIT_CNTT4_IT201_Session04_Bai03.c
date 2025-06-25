#include <stdio.h>

int main(){
    int length;
    printf("nhap so phan tu trong mang: ");
    scanf("%d", &length);
    if (length <= 0) {
        printf("khong hop le");
        return 0;
    }
    int min=99999;
    int minIndex=0;
    for (int i=0; i<length; i++) {
        int check=0;
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &check);
        if (check<min) {
            min=check;
            minIndex=i;
        }
    }
    printf("vi tri phan tu nho nhat: %d", minIndex);
    return 0;
}