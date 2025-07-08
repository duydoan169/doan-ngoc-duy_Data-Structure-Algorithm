#include <stdio.h>
#include <stdlib.h>

typedef struct stack {
    int* arr;
    int capacity;
    int top;
}stack;
stack* createStack(int capacity) {
    stack* newStack=malloc(sizeof(stack));
    newStack->arr=malloc(sizeof(int)*capacity);
    newStack->capacity=capacity;
    newStack->top=-1;
    return newStack;
}
int isFull(stack* stack) {
    if (stack->top+1==stack->capacity) {
        return 1;
    }
    return 0;
}
int push(stack* stack, int value) {
    if (isFull(stack)) {
        printf("stack overflow");
        return 1;
    }
    stack->arr[++stack->top]=value;
    return 0;
}
int isEmpty(stack* stack) {
    if (stack->top==-1) {
        return 1;
    }
    return 0;
}
int pop(stack* stack) {
    if (isEmpty(stack)) {
        printf("stack underflow");
        return -1;
    }
    return stack->arr[stack->top--];
}
int main(void) {
    stack* stack=createStack(5);
    for (int i = 0; i < 5; ++i) {
        int value;
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &value);
        push(stack, value);
    }
    printf("%d", pop(stack));
    return 0;
}