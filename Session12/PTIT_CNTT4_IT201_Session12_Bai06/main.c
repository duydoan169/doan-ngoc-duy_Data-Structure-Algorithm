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
        length++;
        current=current->next;
    }
    return length;
}
void printMid(node* head) {
    if (head==NULL) {
        printf("danh sach lien ket rong");
        return;
    }
    node* current=head;
    int mid=listLength(head)/2 +1;
    int index=1;
    while (current!=NULL) {
        if (index==mid) {
            printf("node %d: %d", index, current->data);
            return;
        }
        index++;
        current=current->next;
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
    printMid(head);
    return 0;
}