#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int** matrix;
} Graph;

Graph* createGraph(int V) {
    Graph* graph = malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = malloc(V * sizeof(int*));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = calloc(V, sizeof(int));
    }
    return graph;
}

void addEdge(Graph* graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}


void DFSUtil(Graph* graph, int src, int* visited) {
    printf("%d ", src);
    visited[src] = 1;
    for (int i = 0; i < graph->V; i++) {
        if (graph->matrix[src][i] == 1 && visited[i] == 0) {
            DFSUtil(graph, i, visited);
        }
    }
}

void DFS(Graph* graph, int src) {
    int* visited = (int*)calloc(graph->V, sizeof(int));
    DFSUtil(graph, src, visited);
    printf("\n");
    free(visited);
}

int main(void) {
    int V, edges;
    printf("Nhap so dinh: ");
    scanf("%d", &V);
    Graph* graph = createGraph(V);

    printf("Nhap so canh: ");
    scanf("%d", &edges);

    printf("Nhap cac canh:\n");
    for (int i = 0; i < edges; i++) {
        int src, dest;
        scanf("%d %d", &src, &dest);
        addEdge(graph, src, dest);
    }

    int src;
    printf("Nhap dinh bat dau DFS: ");
    scanf("%d", &src);
    DFS(graph, src);

    return 0;
}