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
void printMid(node* head) {
    if (head==NULL) {
        printf("danh sach lien ket rong");
        return;
    }
    int length=lengthList(head);
    int mid = length/2;
    node* current=head;
    int index=0;
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
    head->next=createNode(4);
    head->next->next=createNode(3);
    head->next->next->next=createNode(2);
    head->next->next->next->next=createNode(1);
    printMid(head);
    return 0;
}