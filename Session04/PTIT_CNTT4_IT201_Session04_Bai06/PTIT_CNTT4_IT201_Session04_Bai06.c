#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int id;
    char name[20];
    int age;
};
int main(void) {
    struct Student students[5];
    for (int i = 0; i < 5; i++) {
        students[i].id = i+1;
        printf("ten sinh vien thu %d: ", i+1);
        fgets(students[i].name, 20, stdin);
        if (strcspn(students[i].name, "\n") == strlen(students[i].name)) {
            while ((getchar()) != '\n');
        } else {
            students[i].name[strcspn(students[i].name, "\n")]='\0';
        }
        printf("tuoi sinh vien thu %d: ", i+1);
        scanf("%d", &students[i].age);
        getchar();
        printf("\n");
    }
    int find;
    printf("nhap id sinh vien muon tim: ");
    scanf("%d", &find);

    printf("id: %d\n", students[find-1].id);
    printf("ten: %s\n", students[find-1].name);
    printf("tuoi: %d\n", students[find-1].age);
    return 0;
}