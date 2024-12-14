#include <stdio.h>

int max_profit(int prices[], int size) {
    int total_profit = 0;

    for (int i = 1; i < size; i++) {
        if (prices[i] > prices[i - 1]) {
            total_profit += prices[i] - prices[i - 1];
        }
    }

    return total_profit;
}

int main() {
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int size1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("Max profit for prices1: %d\n", max_profit(prices1, size1));

    int prices2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("Max profit for prices2: %d\n", max_profit(prices2, size2));

    int prices3[] = {7, 6, 4, 3, 1};
    int size3 = sizeof(prices3) / sizeof(prices3[0]);
    printf("Max profit for prices3: %d\n", max_profit(prices3, size3));

    return 0;
}