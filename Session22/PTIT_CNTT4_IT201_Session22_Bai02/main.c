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
    Node* newNode1 = createNode(node2);
    newNode1->next = graph[node1];
    graph[node1] = newNode1;

    Node* newNode2 = createNode(node1);
    newNode2->next = graph[node2];
    graph[node2] = newNode2;
}
void showGraph(Node* graph[], int V) {
    for (int i = 0; i < V; i++) {
        printf("%d: ", i);
        Node* temp = graph[i];
        while (temp != NULL) {
            printf("%d ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}
int main(void) {
    int n;
    printf("nhap n: ");
    scanf("%d", &n);
    Node** graph = malloc(n * sizeof(Node*));
    for (int i = 0; i < n; i++) {
        graph[i] = NULL;
    }
    for (int i=0; i<6; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    showGraph(graph, n);
    return 0;
}