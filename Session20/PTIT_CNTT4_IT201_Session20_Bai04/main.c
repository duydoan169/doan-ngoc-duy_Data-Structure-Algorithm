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
typedef struct Queue {
    struct queueNode* front;
    struct queueNode* rear;
}Queue;
Queue* createQueue() {
    Queue* newQueue=malloc(sizeof(Queue));
    newQueue->front=NULL;
    newQueue->rear=NULL;
    return newQueue;
}
typedef struct queueNode {
    Node* root;
    struct queueNode* next;
}queueNode;
queueNode* createQueueNode(Node* root) {
    queueNode* new=malloc(sizeof(queueNode));
    new->root=root;
    new->next=NULL;
    return new;
}
void push(Queue* queue, Node* root) {
    queueNode* temp=createQueueNode(root);
    if (queue->rear==NULL) {
        queue->front=temp;
        queue->rear=temp;
    }else {
        queue->rear->next=temp;
        queue->rear=temp;
    }
}
Node* pop(Queue* queue) {
    if (queue->front==NULL) {
        printf("hang doi rong");
        return NULL;
    }
    queueNode* temp=queue->front;
    Node* returnRoot=temp->root;
    queue->front=queue->front->next;
    if (queue->front==NULL) {
        queue->rear=NULL;
    }
    free(temp);
    return returnRoot;
}
void inorder(Node* root){
    if (root==NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int countLeaf(Node* root) {
    int count=0;
    if (root==NULL) {
        return count;
    }
    Queue* queue=createQueue();
    push(queue, root);
    while (queue->front!=NULL) {
        Node* current=pop(queue);
        if (current->left==NULL && current->right==NULL) {
            count++;
        }
        if (current->left) {
            push(queue, current->left);
        }
        if (current->right) {
            push(queue, current->right);
        }
    }
    free(queue);
    return count;
}
int main(void) {
    Node* root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->left->left=createNode(5);
    printf("so la trong cay: %d", countLeaf(root));
    return 0;
}