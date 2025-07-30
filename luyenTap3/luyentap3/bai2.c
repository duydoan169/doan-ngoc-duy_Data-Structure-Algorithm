#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Operation {
    char url[100];
    char timeStamp[100];
}Operation;
typedef struct Stack {
    Operation* operation;
    int top;
    int cap;
}Stack;
typedef struct Queue {
    Operation* operation;
    int cap;
    int front;
    int rear;
}Queue;
typedef struct Node {
    Operation operation;
    struct Node* next;
    struct Node* prev;
}Node;
Stack* createStack(int cap) {
    Stack* newStack=malloc(sizeof(Stack));
    newStack->operation=malloc(sizeof(Operation)*cap);
    newStack->cap=cap;
    newStack->top=-1;
    return newStack;
}
Queue* createQueue(int cap) {
    Queue* newQueue=malloc(sizeof(Queue));
    newQueue->operation=malloc(sizeof(Operation)*cap);
    newQueue->cap=cap;
    newQueue->front=0;
    newQueue->rear=-1;
    return newQueue;
}
Node* createNode(Operation operation) {
    Node* newNode=malloc(sizeof(Node));
    newNode->operation=operation;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}

Operation visit() {
    Operation operation;
    getchar();
    printf("enter url: ");
    fgets(operation.url, 100, stdin);
    if (strcspn(operation.url, "\n")==strlen(operation.url)) {
        while (getchar()!='\n');
    }else {
        operation.url[strcspn(operation.url, "\n")]='\0';
    }
    printf("enter timeStamp: ");
    fgets(operation.timeStamp, 100, stdin);
    if (strcspn(operation.timeStamp, "\n")==strlen(operation.timeStamp)) {
        while (getchar()!='\n');
    }else {
        operation.timeStamp[strcspn(operation.timeStamp, "\n")]='\0';
    }
    return operation;
}
void pushBackward(Stack* backward, Operation operation) {
    if (backward->top+1==backward->cap) {
        printf("stack overflow\n");
        return;
    }
    backward->operation[++backward->top]=operation;
}
void pushQueue(Queue* queue, Operation operation) {
    if (queue->rear+1==queue->cap) {
        for (int i = queue->front; i < queue->rear; i++) {
            queue->operation[i]=queue->operation[i+1];
        }
        queue->operation[queue->rear]=operation;
        return;
    }
    queue->operation[++queue->rear]=operation;
}
Node* pushNode(Node* head, Operation operation) {
    if (head==NULL) {
        return createNode(operation);
    }
    Node* temp=head;
    while (temp->next!=NULL) {
        temp=temp->next;
    }
    temp->next=createNode(operation);
    temp->next->prev=temp;
    return head;
}
void showCurrent(Operation operation) {
    printf("current information: \n");
    printf("url: %s\n", operation.url);
    printf("timeStamp: %s\n", operation.timeStamp);
}
Operation popBackward(Stack* backward, Operation current, int *check) {
    if (backward->top==-1) {
        printf("stack underflow\n");
        *check=1;
        return current;
    }
    return backward->operation[backward->top--];
}
void pushForward(Stack* forward, Operation operation) {
    if (forward->top+1==forward->cap) {
        printf("stack overflow\n");
        return;
    }
    forward->operation[++forward->top]=operation;
}
Operation popForward(Stack* forward, Operation current) {
    if (forward->top==-1) {
        printf("stack underflow\n");
        return current;
    }
    return forward->operation[forward->top--];
}
void showRecent(Queue* queue) {
    if (queue->front>queue->rear) {
        printf("no recently visited website\n");
        return;
    }
    printf("recently visited website info: \n\n");
    for (int i=queue->rear; i>=queue->front; i--) {
        printf("url: %s\n", queue->operation[i].url);
        printf("timeStamp: %s\n\n", queue->operation[i].timeStamp);
    }
}
void showHistory(Node* head) {
    if (head==NULL) {
        printf("history empty\n");
        return;
    }
    Node* current=head;
    printf("history: \n\n");
    while (current->next!=NULL) {
        current=current->next;
    }
    while (current!=NULL) {
        printf("url: %s\n", current->operation.url);
        printf("timeStamp: %s\n\n", current->operation.timeStamp);
        current=current->prev;
    }
}
Node* clearHistory(Node* head) {
    while (head != NULL) {
        Node* temp=head;
        head = head->next;
        free(temp);
    }
    return NULL;
}
int main(void) {
    Stack* backward=createStack(100);
    Stack* forward=createStack(100);
    Operation current={"", ""};
    Queue* queue=createQueue(5);
    Node* head=NULL;
    int n;
    int check=0;
    do {
        printf("\n========MENU========\n");
        printf("1. VISIT\n");
        printf("2. BACKWARD\n");
        printf("3. FORWARD\n");
        printf("4. CURRENT\n");
        printf("5. RECENT\n");
        printf("6. HISTORY\n");
        printf("7. CLEAR HISTORY\n");
        printf("8. EXIT\n");
        printf("=======================\n");
        printf("enter your choice: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                if (strlen(current.url) > 0) {
                    pushBackward(backward, current);  // only push if current isn't empty
                }
                current = visit();  // now update current to new page
                pushQueue(queue, current);
                head = pushNode(head, current);
                forward->top = -1;  // clear forward stack
                break;
            case 2:
                check = 0;
                Operation temp = popBackward(backward, current, &check);
                if (check == 0) {
                    pushForward(forward, current);
                    current = temp;
                    pushQueue(queue, current);
                    head = pushNode(head, current);
                }
                break;
            case 3:
                if (forward->top != -1) {
                    pushBackward(backward, current);
                    current = popForward(forward, current);
                    pushQueue(queue, current);
                    head = pushNode(head, current);
                } else {
                    printf("stack underflow\n");
                }
                break;
            case 4:
                showCurrent(current);
                break;
            case 5:
                showRecent(queue);
                break;
            case 6:
                showHistory(head);
                break;
            case 7:
                head=clearHistory(head);
                break;
            case 8:
                printf("exited the program\n");
                break;
        }
    }while (n!=8);
    return 0;
}