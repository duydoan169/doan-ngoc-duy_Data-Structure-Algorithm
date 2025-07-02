#include <stdio.h>
#include <stdlib.h>

typedef struct node {
    int data;
    struct node *next;
} node;

node* createNode(int value) {
    node* newNode=malloc(sizeof(node));
    newNode->data = value;
    newNode->next = NULL;
    return newNode;
}
void printNode(node* head) {
    if (head==NULL) {
        printf("khong co phan tu");
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
node* addNode(node* head, int value) {
    node* current=createNode(value);
    current->next=head;
    return current;
}
node* addNode2(node* head, int value, int position) {
    if (position==1) {
        return addNode(head, value);
    } else if (position==5) {
        node* current = head;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = createNode(value);
        return head;
    } else {
        node* current=head;
        int index=1;
        while (current!=NULL) {
            if (index+1==position) {
                node* newNode=createNode(value);
                newNode->next=current->next;
                current->next=newNode;
                break;
            }
            current=current->next;
            index++;
        }
        return head;
    }
}
int main(void) {
    node* head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);
    int value;
    int position;
    printf("nhap phan tu muon them: ");
    scanf("%d", &value);
    printf("nhap vi tri muon them: ");
    scanf("%d", &position);
    if (position<=0 || position>5) {
        printf("khong hop le");
        return 0;
    }
    head = addNode2(head, value, position);
    printNode(head);
    return 0;
}