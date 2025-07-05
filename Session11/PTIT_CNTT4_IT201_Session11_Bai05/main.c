#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
    struct node* prev;
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
    int index=1;
    while (current!=NULL) {
        printf("node %d: %d\n", index, current->data);
        current=current->next;
        index++;
    }
}
void searchNode(node* head, int searchValue) {
    if (head==NULL) {
        printf("danh sach lien ket rong");
        return;
    }
    node* current=head;
    while (current!=NULL) {
        if (current->data==searchValue) {
            printf("true");
            return;
        }
        current=current->next;
    }
    printf("false");
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
node* addNodeB(node* head, int value) {
    if (head==NULL) {
        return createNode(value);
    }
    head->prev=createNode(value);
    head->prev->next=head;
    head=head->prev;
    return head;
}
int main(void) {
    node* head=createNode(1);
    node* node2=createNode(2);
    node* node3=createNode(3);
    node* node4=createNode(4);
    node* node5=createNode(5);
    head->next=node2;
    node2->next=node3;
    node2->prev=head;
    node3->next=node4;
    node3->prev=node2;
    node4->next=node5;
    node4->prev=node3;
    node5->prev=node4;
    int value;
    printf("nhap phan tu muon them: ");
    scanf("%d", &value);
    head=addNodeB(head, value);
    printNode(head);
    return 0;
}