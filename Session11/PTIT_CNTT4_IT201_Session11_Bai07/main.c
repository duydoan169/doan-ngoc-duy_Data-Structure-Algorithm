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
node* addNodeS(node* head, int value, int position) {
    if (head==NULL) {
        return createNode(value);
    }
    if (position<1 || position>listLength(head)+1) {
        printf("khong hop le");
        return head;
    }
    if (position==1) {
        node* newNode=createNode(value);
        newNode->next=head;
        head->prev=newNode;
        head=newNode;
        return head;
    }
    node* current=head;
    for (int i=0; i<position-2; i++) {
        current=current->next;
    }
    node* newNode=createNode(value);
    if (current->next!=NULL) {
        current->next->prev=newNode;
        newNode->next=current->next;
    }
    current->next=newNode;
    newNode->prev=current;
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
    int value, position;
    printf("nhap phan tu muon them: ");
    scanf("%d", &value);
    printf("nhap vi tri muon them: ");
    scanf("%d", &position);
    head=addNodeS(head, value, position);
    printNode(head);
    return 0;
}