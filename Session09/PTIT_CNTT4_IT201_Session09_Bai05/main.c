#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* createNode(int value) {
    node* newNode=malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void printNode(node* head) {
    if (head==NULL) {
        printf("khong co phan tu");
        return;
    }
    node* current=head;
    int index=1;
    while (current!=NULL) {
        printf("node %d: %d\n", index, current->data);
        current=current->next;
        index++;
    }
}
node* addNode(node* head, int value) {
    node* current=createNode(value);
    current->next=head;
    return current;
}
int main(void) {
    node* head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);
    int value;
    printf("nhap phan tu muon them: ");
    scanf("%d", &value);
    head=addNode(head, value);
    printNode(head);
    return 0;
}