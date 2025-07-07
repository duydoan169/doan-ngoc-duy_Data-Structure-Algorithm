#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node* prev;
    struct node* next;
}node;
node* createNode(int value) {
    node* newNode=malloc(sizeof(node));
    newNode->data=value;
    newNode->next=NULL;
    newNode->prev=NULL;
    return newNode;
}
void printNode(node* head) {
    if (head==NULL) {
        printf("danh sach lien ket rong");
        return;
    }
    node* current=head;
    while (current!=NULL) {
        printf("data: %d\n", current->data);
        current=current->next;
    }
}
node* delNodeL(node* head) {
    if (head==NULL) {
        printf("danh sach lien ket rong");
        return NULL;
    }
    if (head->next==NULL && head->prev==NULL) {
        free(head);
        return NULL;
    }
    node* current=head;
    while (current->next!=NULL) {
        current=current->next;
    }
    current->prev->next=NULL;
    free(current);
    return head;
}
int main(void) {
    node* head=createNode(5);
    node* node2=createNode(4);
    node* node3=createNode(3);
    node* node4=createNode(2);
    node* node5=createNode(1);
    head->next=node2;
    node2->next=node3;
    node2->prev=head;
    node3->next=node4;
    node3->prev=node2;
    node4->next=node5;
    node4->prev=node3;
    node5->prev=node4;
    head=delNodeL(head);
    printNode(head);
    return 0;
}