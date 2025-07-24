#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int V, edges;
    printf("nhap so dinh va so canh: ");
    scanf("%d %d", &V, &edges);
    int *arr=calloc(V, sizeof(int));
    printf("nhap cac canh: ");
    for (int i = 0; i < edges; i++) {
        int a,b;
        scanf("%d %d", &a, &b);
        arr[a]++;
        arr[b]++;
    }
    int check;
    printf("nhap dinh muon kiem tra: ");
    scanf("%d", &check);
    printf("so dinh ke voi %d la: %d", check, arr[check]);
    return 0;
}
