#include <stdio.h>
#include <stdlib.h>
int main(void) {
    int n;
    printf("Nhap so dinh: ");
    scanf("%d", &n);
    if (n<=0 || n>=100) {
        printf("khong hop le\n");
        return 0;
    }
    int** matrix = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(int));
    }
    int count=0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
            if (matrix[i][j]==1) {
                count++;
            }
        }
    }
    printf("%d", count/2);
    return 0;
}