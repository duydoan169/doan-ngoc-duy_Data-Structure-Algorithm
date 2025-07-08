#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
int bracketCheck(char str[]) {
    int length=strlen(str);
    stack* stack=createStack(length);
    for (int i = 0; i < length; ++i) {
        if (str[i]=='(' || str[i]=='[' || str[i]=='{') {
            push(stack, str[i]);
        }else if (str[i] == ')' || str[i] == ']' || str[i] == '}') {
            if (isEmpty(stack)) return 1;
            if ((str[i]==')' && stack->arr[stack->top]!='(') || (str[i]==']' && stack->arr[stack->top]!='[') || (str[i]=='}' && stack->arr[stack->top]!='{')) {
                return 1;
            } else {
                pop(stack);
            }
        }
    }
    if (isEmpty(stack)) return 0;
    return 1;
}
int main(void) {
    char str[50];
    printf("nhap chuoi bat ki: ");
    fgets(str, 50, stdin);
    if (strcspn(str, "\n")==strlen(str)) {
        while (getchar()!='\n');
    }else {
        str[strcspn(str, "\n")]='\0';
    }
    if (bracketCheck(str)) {
        printf("false");
    }else {
        printf("true");
    }
    return 0;
}