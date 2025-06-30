#include <stdio.h>
#include <string.h>
void sortStr(char str[]);
int main(void) {
    char str[50];
    printf("nhap chuoi bat ki: ");
    fgets(str, 50, stdin);
    if (strcspn(str, "\n")==strlen(str)) {
        while (getchar() != '\n');
    } else {
        str[strcspn(str, "\n")]='\0';
    }
    if (str[0] == ' ') {
        printf("chuoi khong hop le");
        return 0;
    }
    sortStr(str);
    printf("str = ");
    for (int i=0; i<strlen(str); i++) {
        printf("%c", str[i]);
    }
    return 0;
}
void sortStr(char str[]) {
    for (int i=1; i< strlen(str); i++) {
        int key = str[i];
        int j;
        for (j=i-1; j>=0 && key < str[j]; j--) {
            str[j+1]=str[j];
        }
        str[j+1]=key;
    }
}