#include <stdio.h>
#include <string.h>
int palindromeCheck(char str[], int i, int check);
int main(void) {
    char str[50];
    printf("nhap chuoi ki tu: ");
    fgets(str, sizeof(str), stdin);
    if ((strcspn(str, "\n")) == strlen(str)) {
        while ((getchar())!='\n');
    } else {
        str[strcspn(str, "\n")] = '\0';
    }
    palindromeCheck(str, 0, 0);
    return 0;
}
int palindromeCheck(char str[], int i, int check) {
    if (i == strlen(str)/2) {
        if (check != 0) {
            printf("palindrome invalid");
            return 1;
        } else {
            printf("palindrome valid");
            return 0;
        }
    }
    if (str[i] == str[strlen(str)-i-1]) {
        return palindromeCheck(str, i+1, check);
    } else {
        return palindromeCheck(str, i+1, 1);
    }
}