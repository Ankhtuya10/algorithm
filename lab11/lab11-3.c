#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

#define MAX_QUEUE_SIZE 10000
typedef struct {
    char state[5]; 
    int moves;    
} QueueNode;

typedef struct {
    QueueNode queue[MAX_QUEUE_SIZE];
    int front, rear;
} Queue;

void initQueue(Queue* q) {
    q->front = 0;
    q->rear = 0;
}

bool isQueueEmpty(Queue* q) {
    return q->front == q->rear;
}

void enqueue(Queue* q, char* state, int moves) {
    strcpy(q->queue[q->rear].state, state);
    q->queue[q->rear].moves = moves;
    q->rear++;
}

QueueNode dequeue(Queue* q) {
    return q->queue[q->front++];
}

bool isVisited(char* state, char visited[][5], int visitedCount) {
    for (int i = 0; i < visitedCount; i++) {
        if (strcmp(state, visited[i]) == 0) {
            return true;
        }
    }
    return false;
}

bool isDeadend(char* state, char deadends[][5], int deadendCount) {
    for (int i = 0; i < deadendCount; i++) {
        if (strcmp(state, deadends[i]) == 0) {
            return true;
        }
    }
    return false;
}

void getNeighbors(char* state, char neighbors[][5]) {
    for (int i = 0; i < 4; i++) {
        char temp[5];
        strcpy(temp, state);
        for (int move = -1; move <= 1; move += 2) {
            int digit = temp[i] - '0';
            int new_digit = (digit + move + 10) % 10;
            temp[i] = new_digit + '0';
            strcpy(neighbors[i * 2 + (move == 1)], temp);
        }
    }
}

int openLock(char deadends[][5], int deadendCount, char* target) {
    char start[] = "0000";
    
    if (isDeadend(start, deadends, deadendCount)) {
        return -1;
    }

    Queue q;
    initQueue(&q);
    enqueue(&q, start, 0);

    char visited[10000][5];
    int visitedCount = 0;
    strcpy(visited[visitedCount++], start);

    while (!isQueueEmpty(&q)) {
        QueueNode current = dequeue(&q);
        
        if (strcmp(current.state, target) == 0) {
            return current.moves;
        }
        
        char neighbors[8][5];
        getNeighbors(current.state, neighbors);

        for (int i = 0; i < 8; i++) {
            if (!isVisited(neighbors[i], visited, visitedCount) && !isDeadend(neighbors[i], deadends, deadendCount)) {
                enqueue(&q, neighbors[i], current.moves + 1);
                strcpy(visited[visitedCount++], neighbors[i]);
            }
        }
    }
    return -1;
}

int main() {
    char deadends1[][5] = {"0201", "0101", "0102", "1212", "2002"};
    printf("%d\n", openLock(deadends1, 5, "0202"));  // Expected output: 6

    char deadends2[][5] = {"8888"};
    printf("%d\n", openLock(deadends2, 1, "0009"));  // Expected output: 1

    char deadends3[][5] = {"8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"};
    printf("%d\n", openLock(deadends3, 8, "8888"));  // Expected output: -1

    return 0;
}