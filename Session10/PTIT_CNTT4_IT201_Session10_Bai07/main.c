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
void sortList(node* head) {
    if (head==NULL) {
        return;
    }
    int length=lengthList(head);
    node* current=head;
    for (int i=0; i<length-1; i++) {
        current=head;
        for (int j=0; j<length-i-1; j++) {
            if (current->data > current->next->data) {
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
    head->next=createNode(4);
    head->next->next=createNode(3);
    head->next->next->next=createNode(2);
    head->next->next->next->next=createNode(1);
    sortList(head);
    printNode(head);
    return 0;
}