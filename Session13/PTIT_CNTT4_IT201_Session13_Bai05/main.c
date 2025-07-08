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
void printStack(stack* stack) {
    if (isEmpty(stack)) {
        printf("nang xep rong");
        return;
    }
    for (int i=stack->top; i>=0; i--) {
        printf("%d ", stack->arr[i]);
    }
}
void reverseArr(stack* stack, int arr[]) {
    for (int i=0; i<stack->capacity; i++) {
        push(stack, arr[i]);
    }
    printStack(stack);
}
int main(void) {
    int length;
    printf("nhap do dai mang: ");
    scanf("%d", &length);
    if (length<=0 || length>=1000) {
        printf("khong hop le");
    }
    int arr[length];
    for (int i = 0; i < length; ++i) {
        printf("nhap phan tu thu %d: ", i+1);
        scanf("%d", &arr[i]);
    }
    stack* stack=createStack(length);
    reverseArr(stack, arr);
    return 0;
}