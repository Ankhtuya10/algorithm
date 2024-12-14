#include <stdio.h>
#include <stdlib.h>

typedef struct {
    int *keys;
    int *values;
    int size;
    int capacity;
} Memo;

Memo* create_memo(int capacity) {
    Memo *memo = (Memo *)malloc(sizeof(Memo));
    memo->keys = (int *)malloc(capacity * sizeof(int));
    memo->values = (int *)malloc(capacity * sizeof(int));
    memo->size = 0;
    memo->capacity = capacity;
    return memo;
}

void free_memo(Memo *memo) {
    free(memo->keys);
    free(memo->values);
    free(memo);
}

int memo_search(Memo *memo, int key) {
    for (int i = 0; i < memo->size; i++) {
        if (memo->keys[i] == key) {
            return memo->values[i];
        }
    }
    return -1; 
}

void memo_add(Memo *memo, int key, int value) {
    if (memo->size < memo->capacity) {
        memo->keys[memo->size] = key;
        memo->values[memo->size] = value;
        memo->size++;
    }
}

int fib(Memo *memo, int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;

    int memoized = memo_search(memo, n);
    if (memoized != -1) {
        return memoized;
    }

    int result = fib(memo, n - 1) + fib(memo, n - 2);
    memo_add(memo, n, result);
    return result;
}

int main() {
    int n = 10; 

    Memo *memo = create_memo(100);

    int result = fib(memo, n);
    printf("Fibonacci of %d is %d\n", n, result);

    free_memo(memo);

    return 0;
}