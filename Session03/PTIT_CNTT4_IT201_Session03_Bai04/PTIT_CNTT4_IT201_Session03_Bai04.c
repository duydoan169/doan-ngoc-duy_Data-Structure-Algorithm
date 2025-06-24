#include <stdio.h>
#include <stdlib.h>
void minMax(int row, int col, int arr[row][col]);
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
    minMax(row, col, arr);
    return 0;
}
void minMax(int row, int col, int arr[row][col]) {
    int max = arr[0][0];
    int min = arr[0][0];
    for (int i = 0; i < row; i++) {
        for (int j = 0; j < col; j++) {
            if (arr[i][j] > max) {
                max = arr[i][j];
            }
            if (arr[i][j] < min) {
                min = arr[i][j];
            }
        }
    }
    printf("min = %d\n", min);
    printf("max = %d", max);
}