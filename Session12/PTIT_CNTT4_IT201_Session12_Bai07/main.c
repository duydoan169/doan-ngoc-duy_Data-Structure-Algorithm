#include <locale.h>
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
int listLength(node* head) {
    int length=0;
    node* current=head;
    while (current!=NULL) {
        current=current->next;
        length++;
    }
    return length;
}
void sortNode(node* head) {
    if (head==NULL) {
        printf("danh sach lien ket rong");
        return;
    }
    node* current=head;
    int length=listLength(head);
    for (int i=0; i<length-1; i++) {
        current=head;
        for (int j=0; j<length-i-1; j++) {
            if (current->data>current->next->data) {
                int temp=current->data;
                current->data=current->next->data;
                current->next->data=temp;
            }
            current=current->next;
        }
    }
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
    sortNode(head);
    printNode(head);
    return 0;
}