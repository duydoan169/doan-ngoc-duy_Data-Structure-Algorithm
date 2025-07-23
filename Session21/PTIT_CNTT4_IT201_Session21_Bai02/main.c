#include <stdio.h>
#include <stdlib.h>
#define SIZE 4
typedef struct Graph {
    int V;
    int** matrix;
}Graph;
Graph* createGraph(int V) {
    Graph* newGraph=malloc(sizeof(Graph));
    newGraph->V=V;
    newGraph->matrix=malloc(sizeof(int*)*V);
    for (int i=0; i<V; i++) {
        newGraph->matrix[i]=calloc(V, sizeof(int)*V);
    }
    return newGraph;
}
void addEdge(Graph* graph, int src, int dest) {
    if (src>=SIZE || dest>=SIZE || src<0 || dest<0) {
        return;
    }
    graph->matrix[src][dest]=1;
    graph->matrix[dest][src]=1;
}
void showGraph(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    Graph* graph=createGraph(SIZE);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 3);
    showGraph(graph);
    return 0;
}