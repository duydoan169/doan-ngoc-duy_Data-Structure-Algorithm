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
    if (queue->front == NULL) {
        queue->rear = queue->front = newNode;
        return;
    }
    queue->rear->next=newNode;
    queue->rear=newNode;
}
node* peek(queue* queue) {
    if (queue->front == NULL) {
        printf("hang doi rong");
        return NULL;
    }
    return queue->front;
}
int isEmpty(queue* queue) {
    if (queue->front==NULL) {
        return 1;
    }
    return 0;
}
void pop(queue* queue) {
    if (isEmpty(queue)) {
        printf("hnag doi rong");
        return;
    }
    node* temp=queue->front;
    queue->front=queue->front->next;
    printf("%d", temp->data);
    free(temp);
}
int main(void) {
    queue* queue=createQueue();
    push(queue, 1);
    push(queue, 2);
    push(queue, 3);
    push(queue, 4);
    push(queue, 5);
    pop(queue);
    return 0;
}