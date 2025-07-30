#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

typedef struct Student {
    int id;
    char name[100];
    char status[20];
    int avg;
} Student;

typedef struct nodeDouble {
    Student student;
    struct nodeDouble* next;
    struct nodeDouble* prev;
} nodeDouble;

Student activeList[MAX];
int activeCount = 0;
nodeDouble* inactiveHead = NULL;
nodeDouble* inactiveTail = NULL;

nodeDouble* creatDoubleNode(Student s) {
    nodeDouble* newNode = (nodeDouble*)malloc(sizeof(nodeDouble));
    newNode->student = s;
    newNode->next = NULL;
    newNode->prev = NULL;
    return newNode;
}

void pushToInactive(Student s) {
    nodeDouble* newNode = creatDoubleNode(s);
    if (inactiveHead == NULL) {
        inactiveHead = inactiveTail = newNode;
    } else {
        inactiveTail->next = newNode;
        newNode->prev = inactiveTail;
        inactiveTail = newNode;
    }
}

void createStudent() {
    if (activeCount >= MAX) {
        printf("Danh sach sinh vien hoat dong da day!\n");
        return;
    }

    Student s;
    printf("Nhap thong tin sinh vien:\n");
    printf("ID: ");
    scanf("%d", &s.id);
    getchar();
    printf("Ten: ");
    fgets(s.name, sizeof(s.name), stdin);
    s.name[strcspn(s.name, "\n")] = '\0';

    printf("Trang thai (true/false): ");
    fgets(s.status, sizeof(s.status), stdin);
    s.status[strcspn(s.status, "\n")] = '\0';

    printf("Diem trung binh: ");
    scanf("%d", &s.avg);

    if (strcmp(s.status, "true") == 0 || strcmp(s.status, "TRUE") == 0) {
        activeList[activeCount++] = s;
    } else {
        pushToInactive(s);
    }
}

void showStudents() {
    printf("\nDanh sach sinh vien HOAT DONG\n");
    for (int i = 0; i < activeCount; i++) {
        printf("ID: %d\n", activeList[i].id);
        printf("Ten: %s\n", activeList[i].name);
        printf("Trang thai: %s\n", activeList[i].status);
        printf("Diem TB: %d\n\n", activeList[i].avg);
    }

    printf("Danh sach sinh vien khong hoat dong\n");
    nodeDouble* current = inactiveHead;
    while (current != NULL) {
        printf("ID: %d\n", current->student.id);
        printf("Ten: %s\n", current->student.name);
        printf("Trang thai: %s\n", current->student.status);
        printf("Diem TB: %d\n\n", current->student.avg);
        current = current->next;
    }
}

void deleteStudent() {
    int deleteId;
    printf("Nhap ID sinh vien muon xoa: ");
    scanf("%d", &deleteId);

    int found = 0;
    for (int i = 0; i < activeCount; i++) {
        if (activeList[i].id == deleteId) {
            for (int j = i; j < activeCount - 1; j++) {
                activeList[j] = activeList[j + 1];
            }
            activeCount--;
            found = 1;
            break;
        }
    }

    if (found) {
        printf("Da xoa sinh vien.\n");
    } else {
        printf("Khong tim thay sinh vien co ID do.\n");
    }
}

void updateStudent() {
    int updateId;
    printf("Nhap ID sinh vien muon cap nhat: ");
    scanf("%d", &updateId);
    getchar();

    for (int i = 0; i < activeCount; i++) {
        if (activeList[i].id == updateId) {
            printf("Ten moi: ");
            fgets(activeList[i].name, sizeof(activeList[i].name), stdin);
            activeList[i].name[strcspn(activeList[i].name, "\n")] = '\0';

            printf("Diem TB moi: ");
            scanf("%d", &activeList[i].avg);
            getchar();

            printf("Da cap nhat thong tin sinh vien.\n");
            return;
        }
    }

    printf("Khong tim thay sinh vien.\n");
}

void updateStudentStatus() {
    int id;
    printf("Nhap ID muon doi trang thai: ");
    scanf("%d", &id);
    getchar();

    for (int i = 0; i < activeCount; i++) {
        if (activeList[i].id == id) {
            printf("Trang thai moi (true/false): ");
            fgets(activeList[i].status, sizeof(activeList[i].status), stdin);
            activeList[i].status[strcspn(activeList[i].status, "\n")] = '\0';
            printf("Cap nhat trang thai thanh cong.\n");
            return;
        }
    }

    printf("Khong tim thay sinh vien.\n");
}

void sortStudentsByScore() {
    if (activeCount <= 1) {
        printf("Khong du sinh vien de sap xep.\n");
        return;
    }

    for (int i = 0; i < activeCount - 1; i++) {
        for (int j = 0; j < activeCount - i - 1; j++) {
            if (activeList[j].avg > activeList[j + 1].avg) {
                Student temp = activeList[j];
                activeList[j] = activeList[j + 1];
                activeList[j + 1] = temp;
            }
        }
    }

    printf("Da sap xep theo diem TB.\n");
}

void searchStudentById() {
    int id;
    printf("Nhap ID muon tim: ");
    scanf("%d", &id);

    for (int i = 0; i < activeCount; i++) {
        if (activeList[i].id == id) {
            printf("ID: %d\n", activeList[i].id);
            printf("Ten: %s\n", activeList[i].name);
            printf("Trang thai: %s\n", activeList[i].status);
            printf("Diem TB: %d\n", activeList[i].avg);
            return;
        }
    }

    printf("Khong tim thay sinh vien.\n");
}

void showMenu() {
    printf("\n===== MENU =====\n");
    printf("1. Them sinh vien\n");
    printf("2. Hien thi sinh vien\n");
    printf("3. Xoa sinh vien\n");
    printf("4. Sua sinh vien\n");
    printf("5. Doi trang thai sinh vien\n");
    printf("6. Sap xep theo diem TB\n");
    printf("7. Tim kiem theo ID\n");
    printf("8. Thoat\n");
    printf("================\n");
}

int main() {
    int choice;

    do {
        showMenu();
        printf("Nhap lua chon: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                createStudent();
                break;
            case 2:
                showStudents();
                break;
            case 3:
                deleteStudent();
                break;
            case 4:
                updateStudent();
                break;
            case 5:
                updateStudentStatus();
                break;
            case 6:
                sortStudentsByScore();
                break;
            case 7:
                searchStudentById();
                break;
            case 8:
                printf("Da thoat chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le.\n");
        }
    } while (choice != 8);

    return 0;
}
