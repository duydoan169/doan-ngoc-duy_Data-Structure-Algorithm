#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
int searchDFS(Node* root, int searchValue) {
    if (root==NULL) {
        return 0;
    }
    if (root->data==searchValue) {
        return 1;
    }
    return searchDFS(root->left, searchValue) || searchDFS(root->right, searchValue);
}
int main(void) {
    Node* root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->left->left=createNode(5);
    int searchValue;
    printf("nhap phan tu muon tim: ");
    scanf("%d", &searchValue);
    if (searchDFS(root, searchValue)) {
        printf("true\n");
    }else {
        printf("false\n");
    }
    return 0;
}