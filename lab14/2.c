#include <stdio.h>
#include <stdlib.h>

#define MAX_VERTICES 1000
#define INF 1000000000
typedef struct {
    int u, v, weight;
} Edge;
typedef struct {
    Edge* heap[MAX_VERTICES];
    int size;
} PriorityQueue;

void initQueue(PriorityQueue* pq) {
    pq->size = 0;
}

int compareEdges(const void* a, const void* b) {
    return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

void push(PriorityQueue* pq, Edge* edge) {
    pq->heap[pq->size++] = edge;
    qsort(pq->heap, pq->size, sizeof(Edge*), compareEdges);
}

Edge* pop(PriorityQueue* pq) {
    if (pq->size == 0) return NULL;
    return pq->heap[--pq->size];
}

int prims(int n, int m, Edge edges[], int start) {
    int visited[MAX_VERTICES] = {0};
    int minSum = 0;

    PriorityQueue pq;
    initQueue(&pq);
    for (int i = 0; i < m; i++) {
        push(&pq, &edges[i]);
    }

    visited[start] = 1;
    int edgesUsed = 0;

    while (edgesUsed < n - 1) {
        Edge* minEdge = pop(&pq);
        if (minEdge == NULL) break;

        int u = minEdge->u;
        int v = minEdge->v;
        int weight = minEdge->weight;
        if (visited[u] && !visited[v]) {
            visited[v] = 1;
            minSum += weight;
            edgesUsed++;
        } else if (!visited[u] && visited[v]) {
            visited[u] = 1;
            minSum += weight;
            edgesUsed++;
        }
    }

    return minSum;
}

int main() {
    int n, m;
    scanf("%d %d", &n, &m);

    Edge edges[m];
    for (int i = 0; i < m; i++) {
        scanf("%d %d %d", &edges[i].u, &edges[i].v, &edges[i].weight);
    }

    int start;
    scanf("%d", &start);

    int result = prims(n, m, edges, start);
    printf("%d\n", result);

    return 0;
}