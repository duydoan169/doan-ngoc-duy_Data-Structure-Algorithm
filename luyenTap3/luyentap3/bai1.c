#include <locale.h>
#include <math.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct Tree {
    int data;
    struct Tree* left;
    struct Tree* right;
}Tree;
typedef struct Queue {
    struct Node* front;
    struct Node* rear;
}Queue;
typedef struct Node {
    Tree* root;
    struct Node* next;
}Node;
Tree* createTree(int value) {
    Tree* newTree=malloc(sizeof(Tree));
    newTree->data=value;
    newTree->left=NULL;
    newTree->right=NULL;
    return newTree;
}
Queue* createQueue() {
    Queue* newQueue=malloc(sizeof(Queue));
    newQueue->front=NULL;
    newQueue->rear=NULL;
    return newQueue;
}
Node* createNode(Tree* root) {
    Node* newNode=malloc(sizeof(Node));
    newNode->next=NULL;
    newNode->root=root;
    return newNode;
}
void enqueue(Queue* queue, Tree* root) {
    if (queue->front==NULL) {
        queue->front=queue->rear=createNode(root);
    }else {
        Node* temp=createNode(root);
        queue->rear->next=temp;
        queue->rear=temp;
    }
}
Tree* pop(Queue* queue) {
    if (queue->front==NULL) {
        return NULL;
    }
    Node* temp=queue->front;
    Tree* tempRoot=temp->root;
    queue->front=queue->front->next;
    free(temp);
    return tempRoot;
}
Tree* insert(Tree* root, int value) {
    if (root==NULL) {
        return createTree(value);
    }
    if (root->data<value) {
        root->left=insert(root->left, value);
    }else if (root->data>value) {
        root->right=insert(root->right, value);
    }else {
        printf("phan tu da ton tai\n");
    }
    return root;
}
void inorder(Tree* root) {
    if (root==NULL) {
        return;
    }
    inorder(root->left);
    printf("%d ", root->data);
    inorder(root->right);
}
int countLeaves(Tree* root) {
    if (root==NULL) {
        return 0;
    }
    int count=0;
    Queue* queue=createQueue();
    enqueue(queue, root);
    while (queue->front!=NULL) {
        Tree* current=pop(queue);
        if (current->left==NULL && current->right==NULL) {
            count++;
        }
        if (current->left) {
            enqueue(queue, current->left);
        }
        if (current->right) {
            enqueue(queue, current->right);
        }
    }
    free(queue);
    return count;
}
int height(Tree* root) {
    if (root==NULL) {
        return 0;
    }
    int leftHeight=height(root->left);
    int rightHeight=height(root->right);
    if (leftHeight>rightHeight) {
        return leftHeight+1;
    }else {
        return rightHeight+1;
    }
}
int main(void) {
    int n;
    Tree* root=NULL;
    do {
        printf("\n=======MENU=======\n");
        printf("1. insert\n");
        printf("2. delete\n");
        printf("3. traverse\n");
        printf("4. count leaves\n");
        printf("5. height\n");
        printf("6. exit\n");
        printf("==================\n");
        printf("nhap lua chon: ");
        scanf("%d", &n);
        switch (n) {
            case 1:
                int addValue;
                printf("nhap gia tri muon them: ");
                scanf("%d", &addValue);
                root=insert(root, addValue);
                break;
            case 2:
                int deleteValue;
                printf("nhap gia tri muon xoa: ");
                scanf("%d", &deleteValue);

                break;
            case 3:
                if (root==NULL) {
                    printf("cay rong\n");
                }else {
                    inorder(root);
                }
                break;
            case 4:
                printf("so la trong cay la: %d\n", countLeaves(root));
                break;
            case 5:
                printf("chieu cao cau cay la: %d\n", height(root));
                break;
            case 6:
                printf("da thoat chuong trinh\n");
                break;
            default:
                printf("khong hop le\n");
                break;
        }
    }while (n!=6);

    return 0;
}