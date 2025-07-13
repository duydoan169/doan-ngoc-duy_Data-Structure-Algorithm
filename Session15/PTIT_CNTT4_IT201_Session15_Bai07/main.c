#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct customer {
    char str[30];
}customer;
typedef struct queue {
    customer* arr;
    int front;
    int rear;
    int cap;
}queue;

queue* createQueue(int cap) {
    queue* newQueue=malloc((sizeof(queue)));
    newQueue->arr=malloc(sizeof(customer)*cap);
    newQueue->front=0;
    newQueue->rear=-1;
    newQueue->cap=cap;
    return newQueue;
}
void push(queue* queue, char* name) {
    if (queue->rear == queue->cap - 1) {
        printf("hang doi day");
        return;
    }
    queue->rear++;
    strncpy(queue->arr[queue->rear].str, name, 30);
}
void pop(queue* queue) {
    if (queue->front>queue->rear) {
        printf("hang doi rong");
        return;
    }
    queue->front++;
}
void printQueue(queue* queue) {
    if (queue->front>queue->rear) {
        printf("khong co khach hang");
        return;
    }
    for (int i=queue->front; i<=queue->rear; i++) {
        printf("%s\n", queue->arr[i].str);
    }
}
int main(void) {
    queue* queue=createQueue(100);
    int n;
    do {
        printf("\nMENU\n");
        printf("1. them khach hang\n");
        printf("2. phuc vu\n");
        printf("3. hien thi danh sach khach hang\n");
        printf("4. thoat\n");
        printf("nhap lua chon cua ban: ");
        scanf("%d", &n);
        getchar();
        switch (n) {
            case 1:
                char name[30];
                printf("nhap ten khach hang: ");
                fgets(name, 30, stdin);
                if (strcspn(name, "\n")==strlen(name)) {
                    while (getchar()!='\n');
                }else {
                    name[strcspn(name, "\n")]='\0';
                }
                push(queue, name);
                break;
            case 2:
                pop(queue);
                break;
            case 3:
                printQueue(queue);
                break;
        }
    }while (n!=4);
    printf("da thoat chuong trinh!");
    return 0;
}