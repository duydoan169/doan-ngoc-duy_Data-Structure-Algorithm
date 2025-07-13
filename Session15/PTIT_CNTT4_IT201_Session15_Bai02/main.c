#include <stdio.h>
#include <stdlib.h>

typedef struct queue {
    int* arr;
    int rear;
    int front;
    int cap;
}queue;
queue* addQueue(int cap) {
    queue* newQueue=malloc((sizeof(queue)));
    newQueue->arr=malloc(sizeof(int)*cap);
    newQueue->front=0;
    newQueue->rear=-1;
    return newQueue;
}
int isFull(queue* queue) {
    if (queue->rear+1==queue->cap) {
        return 1;
    }
    return 0;
}
void push(queue* queue, int value) {
    if (isFull(queue)) {
        printf("hang doi day");
        return;
    }
    queue->arr[++queue->rear]=value;
}
int main(void) {
    int cap, temp;
    printf("nhap so luong phan tu: ");
    scanf("%d", &cap);
    queue* queue=addQueue(cap);
    for (int i = 0; i < cap; i++) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &temp);
        push(queue, temp);
    }
    return 0;
}