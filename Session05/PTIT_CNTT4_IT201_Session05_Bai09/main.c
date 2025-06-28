#include <stdio.h>
int maze(int row, int col, int rowC, int colC);
int main(void) {
    int row, col;
    printf("nhap hang: ");
    scanf("%d", &row);
    printf("nhap cot: ");
    scanf("%d", &col);
    if (row < 1 || col < 1) {
        printf("khong hop le");
        return 0;
    }
    printf("so duong di tu [0][0] den vi tri vua nhap la: %d", maze(row-1, col-1, 0, 0));
    return 0;
}
int maze(int row, int col, int rowC, int colC) {
    if (rowC > row || colC > col) {
        return 0;
    }
    if (row == rowC && col == colC) {
        return 1;
    }
    return maze(row, col, rowC+1, colC) + maze(row, col, rowC, colC+1);
}