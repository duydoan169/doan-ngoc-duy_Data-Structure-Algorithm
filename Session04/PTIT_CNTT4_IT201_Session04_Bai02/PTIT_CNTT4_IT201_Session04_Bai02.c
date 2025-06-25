#include <stdio.h>

int main(){
    int length;
    printf("nhap so phan tu trong mang: ");
    scanf("%d", &length);
    if (length <= 0) {
        printf("khong hop le");
        return 0;
    }
    int max=-99999;
    int maxIndex=0;
    for (int i=0; i<length; i++) {
        int check=0;
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &check);
        if (check>max) {
            max=check;
            maxIndex=i;
        }
    }
    printf("vi tri phan tu lon nhat: %d", maxIndex);
    return 0;
}