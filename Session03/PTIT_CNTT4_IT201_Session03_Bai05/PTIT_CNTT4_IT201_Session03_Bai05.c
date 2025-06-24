#include <stdio.h>
void diagCalc(int row,int col, int arr[row][col]);
int main() {
    int row, col;
    printf("nhap so luong hang: ");
    scanf("%d", &row);
    printf("nhap so luong cot: ");
    scanf("%d", &col);
    if ((col > 1000 || col <=0) && (row > 1000 || row <=0)) {
        printf("so luong hang va cot khong hop le");
        return 0;
    } else if ((col > 1000 || col <=0)) {
        printf("so luong cot khong hop le");
        return 0;
    } else if ((row > 1000 || row <=0)) {
        printf("so luong hang khong hop le");
        return 0;
    }
    int arr[row][col];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            printf("nhap gia tri hang %d cot %d: ", i+1, j+1);
            scanf("%d", &arr[i][j]);
        }
    }
    if (row!=col) {
        printf("khong ton tai duong cheo");
        return 0;
    }
    diagCalc(row, col, arr);
    return 0;
}
void diagCalc(int row,int col, int arr[row][col]) {
    int mainSum = 0;
    int crossSum = 0;
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (i==j) {
                mainSum += arr[i][j];
            }
            if (j==row-1-i) {
                crossSum += arr[i][j];
            }
        }
    }
    printf("tong duong cheo chinh = %d\n", mainSum);
    printf("tong duong cheo phu = %d", crossSum);
}