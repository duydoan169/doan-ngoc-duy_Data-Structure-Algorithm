#include <stdio.h>
#include <stdlib.h>
typedef struct node {
    int data;
    struct node* next;
}node;
node* createNode(int value) {
    node* newNode=malloc(sizeof(node));
    newNode->data=value;
    newNode->next=NULL;
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
int lengthList(node* head) {
    int length=0;
    while (head!=NULL) {
        length++;
        head=head->next;
    }
    return length;
}
node* delNodeV(node* head, int delValue) {
    node* current=head;
    node* previous=NULL;
    while (current!=NULL) {
        if (current->data==delValue) {
            node* freeNode=current;
            if (previous==NULL) {
                head=current->next;
                current=head;
            } else {
                previous->next=current->next;
                current=current->next;
            }
            free(freeNode);
        }else {
            previous=current;
            current=current->next;
        }
    }
    return head;
}
int main(void) {
    node* head=createNode(5);
    head->next=createNode(4);
    head->next->next=createNode(3);
    head->next->next->next=createNode(2);
    head->next->next->next->next=createNode(1);
    int delValue;
    printf("nhap gia tri muon xoa: ");
    scanf("%d", &delValue);
    head=delNodeV(head, delValue);
    printNode(head);
    return 0;
}