#include <stdio.h>
int maze(int row, int col, int blockedRow, int blockedCol, int rowC, int colC);
int main(void) {
    int row, col, blockedRow, blockedCol;
    printf("nhap hang: ");
    scanf("%d", &row);
    printf("nhap cot: ");
    scanf("%d", &col);
    printf("nhap hang cua o bi chan: ");
    scanf("%d", &blockedRow);
    printf("nhap cot cua o bi chan: ");
    scanf("%d", &blockedCol);
    if (row < 1 || col < 1 || blockedRow < 1 || blockedCol < 1) {
        printf("khong hop le");
        return 0;
    }
    printf("so duong di tu [0][0] den vi tri vua nhap la: %d", maze(row-1, col-1, blockedRow, blockedCol, 0, 0));
    return 0;
}
int maze(int row, int col, int blockedRow, int blockedCol, int rowC, int colC) {
    if (rowC > row || colC > col || (rowC == blockedRow && colC == blockedCol)) {
        return 0;
    }
    if (row == rowC && col == colC) {
        return 1;
    }
    return maze(row, col, blockedRow, blockedCol, rowC+1, colC) + maze(row, col, blockedRow, blockedCol, rowC, colC+1);
}