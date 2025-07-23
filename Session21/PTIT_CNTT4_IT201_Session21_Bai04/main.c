#include <stdio.h>
#include <stdlib.h>
#define SIZE 3
typedef struct Graph {
    int V; //so dinh
    int **matrix;//mang 2 chieu
}Graph;

Graph* createGraph(int V) {
    Graph* newGraph=malloc((sizeof(Graph)));
    newGraph->V=V;
    newGraph->matrix=malloc(sizeof(int*)*V);
    for (int i = 0; i < V; i++) {
        newGraph->matrix[i]=calloc(V, sizeof(int));
    }
    return newGraph;
}
void addEdge(Graph* graph, int src, int dest) {
    if (src >= graph->V || dest >= graph->V || src < 0 || dest < 0) {
        printf("khong hop le\n");
        return;
    }
    graph->matrix[src][dest]=1;
}
void showGraph1(Graph* graph) {
    for (int i = 0; i < graph->V; i++) {
        for (int j = 0; j < graph->V; j++) {
            printf("%d ", graph->matrix[i][j]);
        }
        printf("\n");
    }
}
int main(void) {
    Graph* graph=createGraph(SIZE);
    addEdge(graph, 1, 0);
    addEdge(graph, 1, 2);
    addEdge(graph, 2, 0);
    showGraph1(graph);
    return 0;
}