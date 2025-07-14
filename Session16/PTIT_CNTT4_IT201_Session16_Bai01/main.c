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
int main(void) {
    queue* queue=createQueue();
    return 0;
}