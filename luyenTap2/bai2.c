#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Queue {
    struct Node* front;
    struct Node* rear;
}Queue;
typedef struct Request {
    int id;
    char issue[100];
    int priority;
}Request;
typedef struct Node {
    Request request;
    struct Node* next;
}Node;
Queue* createQueue(){
    Queue* newQueue=malloc(sizeof(Queue));
    newQueue->front=NULL;
    newQueue->rear=NULL;
    return newQueue;
}
Node* createNode(Request request) {
    Node* newNode=malloc(sizeof(Node));
    newNode->request=request;
    newNode->next=NULL;
    return newNode;
}
void createRequest(Queue* queueHigh, Queue* queueLow) {
    Request request;
    getchar();
    printf("nhap yeu cau: ");
    fgets(request.issue, 100, stdin);
    if (strcspn(request.issue, "\n")==strlen(request.issue)) {
        while (getchar()!='\n');
    }else {
        request.issue[strcspn(request.issue, "\n")]='\0';
    }
    printf("nhap do uu tien: ");
    scanf("%d", &request.priority);
    if (request.priority==1) {
        if (queueHigh->front==NULL) {
            request.id=1;
            queueHigh->front=queueHigh->rear=createNode(request);
        }else {
            request.id=queueHigh->rear->request.id+1;
            Node* newNode=createNode(request);
            queueHigh->rear->next=newNode;
            queueHigh->rear=newNode;
        }
    }else {
        if (queueLow->front==NULL) {
            request.id=1;
            queueLow->front=queueLow->rear=createNode(request);
        }else {
            request.id=queueLow->rear->request.id+1;
            Node* newNode=createNode(request);
            queueLow->rear->next=newNode;
            queueLow->rear=newNode;
        }
    }
}
void handleRequest(Queue* queueHigh, Queue* queueLow) {
    if (queueHigh->front==NULL) {
        if (queueLow->front==NULL) {
            printf("khong co yeu cau\n");
        }else {
            Node* temp=queueLow->front;
            queueLow->front=queueLow->front->next;
            if (queueLow->front==NULL) {
                queueLow->rear=NULL;
            }
            free(temp);
        }
    }else {
        Node* temp=queueHigh->front;
        queueHigh->front=queueHigh->front->next;
        if (queueHigh->front==NULL) {
            queueHigh->rear=NULL;
        }
        free(temp);
    }
}
void viewTopRequest(Queue* queueHigh, Queue* queueLow) {
    if (queueHigh->front!=NULL) {
        printf("ID: %d\n", queueHigh->front->request.id);
        printf("Issue: %s\n", queueHigh->front->request.issue);
        printf("Priority: %d\n\n", queueHigh->front->request.priority);
    }else {
        if (queueLow->front==NULL) {
            printf("khong co yeu cau\n");
        }else {
            printf("ID: %d\n", queueLow->front->request.id);
            printf("Issue: %s\n", queueLow->front->request.issue);
            printf("Priority: %d\n\n", queueLow->front->request.priority);
        }
    }
}
void showRequests(Queue* queueHigh, Queue* queueLow) {
    if (queueHigh->front==NULL) {
        printf("khong co yeu cau uu tien cao\n\n");
    }else {
        printf("thong tin yeu cau cao: \n\n");
        Node* current=queueHigh->front;
        while (current!=NULL) {
            printf("ID: %d\n", current->request.id);
            printf("Issue: %s\n", current->request.issue);
            printf("Priority: %d\n\n", current->request.priority);
            current=current->next;
        }
    }
    if (queueLow->front==NULL) {
        printf("khong co yeu cau uu tien thap\n\n");
    }else {
        printf("thong tin yeu cau thap: \n\n");
        Node* current=queueLow->front;
        while (current!=NULL) {
            printf("ID: %d\n", current->request.id);
            printf("Issue: %s\n", current->request.issue);
            printf("Priority: %d\n\n", current->request.priority);
            current=current->next;
        }
    }
}
int main(void) {
    int n;
    Queue* queueHigh=createQueue();
    Queue* queueLow=createQueue();
    do {
        printf("\n==========MENU==========\n");
        printf("1. gui yeu cau\n");
        printf("2. xu li yeu cau\n");
        printf("3. xem yeu cau gan nhat\n");
        printf("4. hien thi\n");
        printf("5. thoat\n");
        printf("=========================\n");
        printf("nhap lua chon cua ban: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                createRequest(queueHigh, queueLow);
                break;
            case 2:
                handleRequest(queueHigh, queueLow);
                break;
            case 3:
                viewTopRequest(queueHigh, queueLow);
                break;
            case 4:
                showRequests(queueHigh, queueLow);
                break;
            case 5:
                printf("da thoat chuong trinh\n");
                break;
            default:
                printf("khong hop le\n");
        }
    }while (n!=5);
    return 0;
}
