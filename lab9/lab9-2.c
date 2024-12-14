#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int* q1;
    int* q2;
    int front1, rear1, front2, rear2, size1, size2, capacity;
} MyStack;
MyStack* myStackCreate(int capacity) {
    MyStack* stack = (MyStack*)malloc(sizeof(MyStack));
    stack->q1 = (int*)malloc(sizeof(int) * capacity);
    stack->q2 = (int*)malloc(sizeof(int) * capacity);
    stack->front1 = stack->rear1 = stack->front2 = stack->rear2 = 0;
    stack->size1 = stack->size2 = 0;
    stack->capacity = capacity;
    return stack;
}
void myStackPush(MyStack* obj, int x) {
    obj->q2[obj->rear2++] = x;
    obj->size2++;
    while (obj->size1 > 0) {
        obj->q2[obj->rear2++] = obj->q1[obj->front1++];
        obj->size1--;
    }
    int* temp = obj->q1;
    obj->q1 = obj->q2;
    obj->q2 = temp;
    obj->size1 = obj->size2;
    obj->size2 = 0;
    obj->front1 = 0;
    obj->rear1 = obj->size1;
    obj->front2 = obj->rear2 = 0;
}
int myStackPop(MyStack* obj) {
    if (obj->size1 > 0) {
        int value = obj->q1[obj->front1++];
        obj->size1--;
        return value;
    }
    return -1;
}
int myStackTop(MyStack* obj) {
    if (obj->size1 > 0) {
        return obj->q1[obj->front1];
    }
    return -1; 
}
int myStackEmpty(MyStack* obj) {
    return obj->size1 == 0;
}
void myStackFree(MyStack* obj) {
    free(obj->q1);
    free(obj->q2);
    free(obj);
}

int main() {
    MyStack* stack = myStackCreate(100);

    myStackPush(stack, 1);
    myStackPush(stack, 2);
    printf("Top: %d\n", myStackTop(stack));  // Output: 2
    printf("Pop: %d\n", myStackPop(stack));  // Output: 2
    printf("Empty: %d\n", myStackEmpty(stack));  // Output: 0 (false)

    myStackFree(stack);
    return 0;
}