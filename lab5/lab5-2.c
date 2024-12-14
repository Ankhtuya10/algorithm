#include <stdio.h>

int knapsack(int weights[], int values[], int n, int W) {
    int dp[n + 1][W + 1];
    for (int i = 0; i <= n; i++) {
        for (int w = 0; w <= W; w++) {
            if (i == 0 || w == 0) {
                dp[i][w] = 0;
            } else if (weights[i - 1] <= w) {
                dp[i][w] = (dp[i - 1][w] > (values[i - 1] + dp[i - 1][w - weights[i - 1]]) ? dp[i - 1][w] : (values[i - 1] + dp[i - 1][w - weights[i - 1]]));
            } else {
                dp[i][w] = dp[i - 1][w];
            }
        }
    }

    return dp[n][W];
}

int main() {
    int values[] = {60, 100, 120};
    int weights[] = {10, 20, 30};
    int W = 50;
    int n = sizeof(values) / sizeof(values[0]);

    int result = knapsack(weights, values, n, W);
    printf("\u04ae\u04af\u0440\u0433\u044d\u0432\u0447\u0438\u043d\u0434 \u0431\u0430\u0433\u0442\u0430\u0445 \u0445\u0430\u043c\u0433\u0438\u0439\u043d \u0438\u0445 \u04af\u043d\u044d \u0446\u044d\u043d\u044d: %d\n", result);

    return 0;
}