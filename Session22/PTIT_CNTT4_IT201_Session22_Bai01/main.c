#include <stdio.h>
#include <stdlib.h>
#define SIZE
typedef struct Graph {
    int V;
    int** matrix;
}Graph;
Graph* createGraph(int V) {
    Graph* newGraph=malloc(sizeof(Graph));
    newGraph->V=V;
    newGraph->matrix=malloc(sizeof(int*)*V);
    for (int i = 0; i < V; i++) {
        newGraph->matrix[i]=calloc(V, sizeof(int));
    }
    return newGraph;
}
void addEdge(Graph* graph, int src, int dest) {
    graph->matrix[src][dest]=1;
    graph->matrix[dest][src]=1;
}
void showGraph(Graph* graph) {
    for (int i=0; i<graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    int n;
    printf("nhap so dinh: ");
    scanf("%d", &n);
    Graph* graph=createGraph(n);
    for (int i=0; i<6; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }
    showGraph(graph);
    return 0;
}