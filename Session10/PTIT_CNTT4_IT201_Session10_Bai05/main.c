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
node* delNodeS(node* head, int position) {
    int length=lengthList(head);
    if (head==NULL) {
        printf("danh sach lien ket rong");
        return head;
    }
    if (position>length || position<=0) {
        printf("khong hop le");
        return head;
    }
    if (position==1) {
        node* current=head->next;
        free(head);
        return current;
    } else if (position==length) {
        node* current=head;
        while (current->next->next!=NULL) {
            current=current->next;
        }
        free(current->next);
        current->next=NULL;
        return head;
    }
    node* current=head;
    int index=0;
    while (index+1!=position) {
        current=current->next;
        index++;
    }
    node* temp=current->next;
    current->next=current->next->next;
    free(temp);
    return head;
}
int main(void) {
    node* head=createNode(5);
    head->next=createNode(4);
    head->next->next=createNode(3);
    head->next->next->next=createNode(2);
    head->next->next->next->next=createNode(1);
    int position;
    printf("nhap vi tri muon xoa: ");
    scanf("%d", &position);
    head=delNodeS(head, position);
    printNode(head);
    return 0;
}