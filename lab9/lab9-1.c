#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct MyQueue {
    int *stack_in;
    int *stack_out;
    int size_in;
    int size_out;
    int capacity_in;
    int capacity_out;
} MyQueue;

void initQueue(MyQueue* obj) {
    obj->capacity_in = 100;
    obj->capacity_out = 100;
    obj->stack_in = (int*)malloc(obj->capacity_in * sizeof(int));
    obj->stack_out = (int*)malloc(obj->capacity_out * sizeof(int));
    obj->size_in = 0;
    obj->size_out = 0;
}

void push(MyQueue* obj, int x) {
    if (obj->size_in == obj->capacity_in) {
        obj->capacity_in *= 2;
        obj->stack_in = (int*)realloc(obj->stack_in, obj->capacity_in * sizeof(int));
    }
    obj->stack_in[obj->size_in++] = x;
}

void transfer_in_to_out(MyQueue* obj) {
    if (obj->size_out == 0) {
        while (obj->size_in > 0) {
            obj->stack_out[obj->size_out++] = obj->stack_in[--obj->size_in];
        }
    }
}

int pop(MyQueue* obj) {
    transfer_in_to_out(obj);
    if (obj->size_out > 0) {
        return obj->stack_out[--obj->size_out];
    }
    return -1; 
}

int peek(MyQueue* obj) {
    transfer_in_to_out(obj);
    if (obj->size_out > 0) {
        return obj->stack_out[obj->size_out - 1];
    }
    return -1; 
}

bool empty(MyQueue* obj) {
    return obj->size_in == 0 && obj->size_out == 0;
}

void freeQueue(MyQueue* obj) {
    free(obj->stack_in);
    free(obj->stack_out);
}

int main() {
    MyQueue queue;
    initQueue(&queue);
    
    push(&queue, 1);
    push(&queue, 2);
    printf("Front element: %d\n", peek(&queue)); // Output: 1
    printf("Popped element: %d\n", pop(&queue));  // Output: 1
    printf("Is empty: %d\n", empty(&queue));     // Output: 0 (false)

    freeQueue(&queue);
    return 0;
}