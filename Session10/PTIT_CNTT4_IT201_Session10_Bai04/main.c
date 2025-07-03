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
node* delNodeL(node* head) {
    int length = lengthList(head);
    if (length==1) {
        free(head);
        return NULL;
    } else if (length==0) {
        printf("danh sach lien ket rong");
        return head;
    }
    node* current=head;
    while (current->next->next!=NULL) {
        current=current->next;
    }
    free(current->next);
    current->next=NULL;
    return head;
}
int main(void) {
    node* head=createNode(5);
    head->next=createNode(4);
    head->next->next=createNode(3);
    head->next->next->next=createNode(2);
    head->next->next->next->next=createNode(1);
    head=delNodeL(head);
    printNode(head);
    return 0;
}