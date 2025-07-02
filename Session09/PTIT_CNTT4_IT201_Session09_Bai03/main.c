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
void searchNode(node* head, int find) {
    node* current=head;
    while (current!=NULL) {
        if (current->data==find) {
            printf("true");
            return;
        }
        current=current->next;
    }
    printf("false");
}
int main(void) {
    node* head=createNode(1);
    head->next=createNode(2);
    head->next->next=createNode(3);
    head->next->next->next=createNode(4);
    head->next->next->next->next=createNode(5);
    int find;
    printf("nhap phan tu muon tim: ");
    scanf("%d", &find);
    searchNode(head, find);
    return 0;
}