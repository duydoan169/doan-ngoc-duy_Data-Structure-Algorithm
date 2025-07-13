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
int main(void) {
    queue* queue=addQueue(5);
    return 0;
}