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
int main(void) {
    stack* stack=createStack();
    return 0;
}