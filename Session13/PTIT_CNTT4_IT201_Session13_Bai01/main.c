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
int main(void) {
    stack* newStack=createStack(5);
    return 0;
}