#include <stdio.h>
void rowCalc(int row, int col, int arr[row][col]);
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
    rowCalc(row, col, arr);
    return 0;
}
void rowCalc(int row, int col, int arr[row][col]) {
    int chosenRow;
    int sum=0;
    printf("nhap hang muon tinh tong: ");
    scanf("%d", &chosenRow);
    if (chosenRow > row || chosenRow < 0) {
        printf("hang can tinh khong ton tai");
        return;
    }
    for (int j = 0; j < col; j++) {
        sum += arr[chosenRow][j];
    }
    printf("sum = %d\n", sum);
}