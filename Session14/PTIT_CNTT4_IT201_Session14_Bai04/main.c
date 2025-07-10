#include <locale.h>
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

typedef struct stack {
    node* top;
}stack;
stack* createStack() {
    stack* newStack=malloc(sizeof(stack));
    newStack->top=NULL;
    return newStack;
}
void push(stack* stack, int value) {
    node* newNode=createNode(value);
    newNode->next=stack->top;
    stack->top=newNode;
}
void printStack(stack* stack) {
    if (stack->top==NULL) {
        printf("ngan xep trong");
        return;
    }
    node* current=stack->top;
    while (current!=NULL) {
        printf("%d\n", current->data);
        current=current->next;
    }
}
void pop(stack* stack) {
    if (stack->top==NULL) {
        printf("ngan xep trong");
        return;
    }
    node* current=stack->top;
    stack->top=current->next;
    free(current);
}
int main(void) {
    stack* stack=createStack();
    push(stack, 5);
    push(stack, 4);
    push(stack, 3);
    push(stack, 2);
    push(stack, 1);
    pop(stack);
    printStack(stack);
    return 0;
}