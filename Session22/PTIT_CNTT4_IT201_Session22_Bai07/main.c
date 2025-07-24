#include <stdio.h>
#include <stdlib.h>

typedef struct Graph {
    int V;
    int **matrix;
} Graph;
Graph *createGraph(int V) {
    Graph *graph =malloc(sizeof(Graph));
    graph->V = V;
    graph->matrix = malloc(V * sizeof(int *));
    for (int i = 0; i < V; i++) {
        graph->matrix[i] = calloc(V, sizeof(int));
    }
    return graph;
}
void addEdge(Graph *graph, int src, int dest) {
    graph->matrix[src][dest] = 1;
    graph->matrix[dest][src] = 1;
}
typedef struct Queue {
    int *arr;
    int capacity;
    int front;
    int rear;
} Queue;
Queue *createQueue(int capacity) {
    Queue *queue = malloc(sizeof(Queue));
    queue->arr = malloc(capacity * sizeof(int));
    queue->capacity = capacity;
    queue->front = 0;
    queue->rear = -1;
    return queue;
}
void enqueue(Queue *queue, int vertex) {
    if (queue->rear == queue->capacity - 1) {
        printf("hang doi day\n");
        return;
    }
    queue->rear++;
    queue->arr[queue->rear] = vertex;
}
int isEmpty(Queue *queue) {
    if (queue->front > queue->rear) {
        return 1;
    }
    return 0;
}
int dequeue(Queue *queue) {
    if (!isEmpty(queue)) {
        return queue->arr[queue->front++];
    }
    return -1;
}
void BFS(Graph *graph, int src) {
    int *visited = calloc(graph->V, sizeof(int));
    Queue *queue = createQueue(graph->V);
    enqueue(queue, src);
    visited[src] = 1;
    while (!isEmpty(queue)) {
        int vertex = dequeue(queue);
        printf("%d ", vertex);
        for (int i = 0; i < graph->V; i++) {
            if (graph->matrix[vertex][i] == 1 && visited[i] == 0) {
                visited[i] = 1;
                enqueue(queue, i);
            }
        }
    }
    printf("\n");
    free(queue->arr);
    free(queue);
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
    printf("Nhap dinh bat dau BFS: ");
    scanf("%d", &src);
    BFS(graph, src);
    return 0;
}