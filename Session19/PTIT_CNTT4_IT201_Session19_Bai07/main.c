#include <locale.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node *left;
    struct Node *right;
}Node;
typedef struct queueNode {
    Node* treeNode;
    struct queueNode* next;
}queueNode;
typedef struct Queue {
    queueNode* front;
    queueNode* rear;
}Queue;
Node* createNode(int data) {
    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->data = data;
    newNode->left = NULL;
    newNode->right = NULL;
    return newNode;
}
Queue* createQueue() {
    Queue* newQueue=malloc(sizeof(Queue));
    newQueue->front=NULL;
    newQueue->rear=NULL;
    return newQueue;
}
queueNode* createQueueNode(Node* root) {
    queueNode* new=malloc(sizeof(queueNode));
    new->treeNode=root;
    new->next=NULL;
    return new;
}
void push(Queue* queue, Node* root) {
    queueNode* temp=createQueueNode(root);
    if (queue->rear==NULL) {
        queue->front=temp;
        queue->rear=temp;
        return;
    }
    queue->rear->next=temp;
    queue->rear=temp;
}
Node* pop(Queue* queue) {
    if (queue->front==NULL) {
        return NULL;
    }
    queueNode* temp=queue->front;
    Node* treeNode=temp->treeNode;
    queue->front=queue->front->next;
    if (queue->front==NULL) {
        queue->rear=NULL;
    }
    free(temp);
    return treeNode;
}
void addNode(Node* root, int value) {
    if (root==NULL) {
        return;
    }
    Queue* queue=createQueue();
    push(queue, root);
    while (queue->front!=NULL) {
        Node* current=pop(queue);
        if (current->left==NULL) {
            current->left=createNode(value);
            break;
        }else {
            push(queue, current->left);
        }
        if (current->right==NULL) {
            current->right=createNode(value);
            break;
        }else {
            push(queue, current->right);
        }
    }
    free(queue);
}
int main(void) {
    Node* root=createNode(2);
    root->left=createNode(3);
    root->right=createNode(4);
    root->left->left=createNode(5);
    int value;
    printf("nhap phan tu muon them: ");
    scanf("%d", &value);
    addNode(root, value);
    return 0;
}