#include <stdio.h>
#include <stdlib.h>
typedef struct Node {
    int data;
    struct Node* next;
}Node;
Node* createNode(int value) {
    Node* newNode=malloc(sizeof(Node));
    newNode->data=value;
    newNode->next=NULL;
    return newNode;
}
void addEdge(Node* graph[], int node1, int node2) {
    Node* newNode1=createNode(node2);
    newNode1->next=graph[node1];
    graph[node1]=newNode1;
}
void matrixToList(Node* graph[], int* matrix[], int n) {
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
        for (int j = n - 1; j >= 0; j--) {
            if (matrix[i][j] == 1) {
                addEdge(graph, i, j);
            }
        }
    }
}
void showGraph(Node* graph[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d: ", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("NULL\n");
    }
}
int main(void) {
    int n;
    printf("Nhap so dinh: ");
    scanf("%d", &n);
    if (n<=0 || n>=100) {
        printf("khong hop le\n");
        return 0;
    }
    int** matrix = malloc(n * sizeof(int*));
    for (int i = 0; i < n; i++) {
        matrix[i] = malloc(n * sizeof(int));
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            scanf("%d", &matrix[i][j]);
        }
    }
    Node** graph = malloc(n * sizeof(Node*));
    matrixToList(graph, matrix, n);
    showGraph(graph, n);
    return 0;
}