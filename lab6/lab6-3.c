#include <stdio.h>

int maxProfit(int* prices, int pricesSize) {
    int totalProfit = 0;

    for (int i = 0; i < pricesSize - 1; i++) {
        if (prices[i] < prices[i + 1]) {
            totalProfit += prices[i + 1] - prices[i];
        }
    }

    return totalProfit;
}

int main() {
    int prices1[] = {7, 1, 5, 3, 6, 4};
    int size1 = sizeof(prices1) / sizeof(prices1[0]);
    printf("%d\n", maxProfit(prices1, size1));

    int prices2[] = {1, 2, 3, 4, 5};
    int size2 = sizeof(prices2) / sizeof(prices2[0]);
    printf("%d\n", maxProfit(prices2, size2));

    int prices3[] = {7, 6, 4, 3, 1};
    int size3 = sizeof(prices3) / sizeof(prices3[0]);
    printf("%d\n", maxProfit(prices3, size3));

    return 0;
}