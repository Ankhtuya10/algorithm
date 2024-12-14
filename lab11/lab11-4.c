#include <stdio.h>
#include <stdlib.h>

#define MAX_COURSES 1000
int state[MAX_COURSES];
int topological_order[MAX_COURSES];
int is_possible = 1;  
int adj_list[MAX_COURSES][MAX_COURSES];
int adj_size[MAX_COURSES];

void dfs(int node) {
    if (!is_possible) return; 

    state[node] = 1;  
    for (int i = 0; i < adj_size[node]; i++) {
        int neighbor = adj_list[node][i];
        if (state[neighbor] == 0) {  
            dfs(neighbor);
        } else if (state[neighbor] == 1) {  
            is_possible = 0;
            return;
        }
    }

    state[node] = 2;  
    topological_order[--topological_order[0]] = node; 
}
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize) {
    *returnSize = 0;
    topological_order[0] = numCourses;  
    is_possible = 1;
    for (int i = 0; i < numCourses; i++) {
        adj_size[i] = 0;
        state[i] = 0;
    }
    for (int i = 0; i < prerequisitesSize; i++) {
        int course = prerequisites[i][0];
        int prereq = prerequisites[i][1];
        adj_list[prereq][adj_size[prereq]++] = course;
    }
    for (int i = 0; i < numCourses; i++) {
        if (state[i] == 0) {
            dfs(i);
        }
    }
    if (!is_possible) {
        *returnSize = 0;
        return NULL;
    }
    *returnSize = numCourses;
    return topological_order + 1;  
}
int main() {
    int numCourses1 = 2;
    int prerequisites1[][2] = {{1, 0}};
    int *prerequisitesPtr1[] = {prerequisites1[0], prerequisites1[1]};
    int returnSize1;
    int* result1 = findOrder(numCourses1, prerequisitesPtr1, 1, NULL, &returnSize1);
    if (result1 != NULL) {
        for (int i = 0; i < returnSize1; i++) {
            printf("%d ", result1[i]);
        }
    } else {
        printf("[]");
    }
    printf("\n");

    int numCourses2 = 4;
    int prerequisites2[][2] = {{1, 0}, {2, 0}, {3, 1}, {3, 2}};
    int *prerequisitesPtr2[] = {prerequisites2[0], prerequisites2[1], prerequisites2[2], prerequisites2[3]};
    int returnSize2;
    int* result2 = findOrder(numCourses2, prerequisitesPtr2, 4, NULL, &returnSize2);
    if (result2 != NULL) {
        for (int i = 0; i < returnSize2; i++) {
            printf("%d ", result2[i]);
        }
    } else {
        printf("[]");
    }
    printf("\n");

    int numCourses3 = 1;
    int prerequisites3[][2] = {};
    int *prerequisitesPtr3[] = {};
    int returnSize3;
    int* result3 = findOrder(numCourses3, prerequisitesPtr3, 0, NULL, &returnSize3);
    if (result3 != NULL) {
        for (int i = 0; i < returnSize3; i++) {
            printf("%d ", result3[i]);
        }
    } else {
        printf("[]");
    }
    printf("\n");

    return 0;
}