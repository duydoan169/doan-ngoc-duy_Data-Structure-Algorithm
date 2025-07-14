#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* next;
}node;
node* createNode(int value) {
    node* newNode=malloc((sizeof(node)));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
typedef struct queue{
    node* front;
    node* rear;
}queue;
queue* createQueue() {
    queue* newQueue=malloc(sizeof(queue));
    newQueue->front = newQueue->rear = NULL;
    return newQueue;
}
void push(queue* queue, int value) {
    node* newNode=createNode(value);
    if (queue->front == queue->rear && queue->rear == NULL) {
        queue->rear = queue->front = newNode;
        return;
    }
    queue->rear->next=newNode;
    queue->rear=newNode;
}
int main(void) {
    queue* queue=createQueue();
    int value;
    printf("nhap phan tu muon them: ");
    scanf("%d", &value);
    push(queue, value);
    return 0;
}