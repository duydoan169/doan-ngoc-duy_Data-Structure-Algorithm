#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    struct Node* left;
    struct Node* right;
    int data;
}Node;
Node* createNode(int value){
    Node* newNode=malloc((sizeof(Node)));
    newNode->left=NULL;
    newNode->right=NULL;
    newNode->data=value;
    return newNode;
}
int main(void) {
    Node* root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->left->left=createNode(5);
    return 0;
}