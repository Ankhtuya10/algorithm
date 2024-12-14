#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_NODES 6
void dfs(int node, bool visited[], int stack[], int* stack_index, int graph[MAX_NODES][MAX_NODES], int num_nodes);
void topological_sort(int graph[MAX_NODES][MAX_NODES], int num_nodes, int stack[]);
void dfs(int node, bool visited[], int stack[], int* stack_index, int graph[MAX_NODES][MAX_NODES], int num_nodes) {
    visited[node] = true;
    for (int i = 0; i < num_nodes; i++) {
        if (graph[node][i] == 1 && !visited[i]) {
            dfs(i, visited, stack, stack_index, graph, num_nodes);
        }
    }
    stack[(*stack_index)++] = node;
}
void topological_sort(int graph[MAX_NODES][MAX_NODES], int num_nodes, int stack[]) {
    bool visited[MAX_NODES] = {false};
    int stack_index = 0;

    for (int i = 0; i < num_nodes; i++) {
        if (!visited[i]) {
            dfs(i, visited, stack, &stack_index, graph, num_nodes);
        }
    }
    for (int i = 0; i < stack_index / 2; i++) {
        int temp = stack[i];
        stack[i] = stack[stack_index - i - 1];
        stack[stack_index - i - 1] = temp;
    }
}
void test_topological_sort() {
    int graph[MAX_NODES][MAX_NODES] = { {0, 0, 0, 0, 1, 1},   // Node 0: [4, 5]
                                        {0, 0, 0, 1, 1, 0},   // Node 1: [3, 4]
                                        {0, 0, 0, 0, 0, 1},   // Node 2: [5]
                                        {0, 0, 1, 0, 0, 0},   // Node 3: [1]
                                        {0, 0, 0, 0, 0, 0},   // Node 4: []
                                        {0, 0, 0, 0, 0, 0} }; // Node 5: []

    int stack[MAX_NODES];
    
    topological_sort(graph, MAX_NODES, stack);
    printf("Topological Sort: ");
    for (int i = 0; i < MAX_NODES; i++) {
        printf("%d ", stack[i]);
    }
    printf("\n");
}

int main() {
    test_topological_sort();
    return 0;
}