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
void countNode(node* head) {
    node* current=head;
    int count=0;
    while (current!=NULL) {
        count++;
        current=current->next;
    }
    printf("danh sach lien ket co %d phan tu", count);
}
int main(void) {
    node* head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);
    countNode(head);
    return 0;
}