#include <stdio.h>
#include <limits.h>

int numTrees(int n) {
    int dp[n + 1];
    dp[0] = 1;
    dp[1] = 1;

    for (int nodes = 2; nodes <= n; nodes++) {
        dp[nodes] = 0;
        for (int root = 1; root <= nodes; root++) {
            int leftTrees = dp[root - 1];
            int rightTrees = dp[nodes - root];
            dp[nodes] += leftTrees * rightTrees;
        }
    }

    return dp[n];
}

int sum(int freq[], int start, int end) {
    int total = 0;
    for (int i = start; i <= end; i++) {
        total += freq[i];
    }
    return total;
}

int optimalBST(int keys[], int freq[], int n) {
    int dp[n][n];

    for (int i = 0; i < n; i++) {
        dp[i][i] = freq[i];
    }

    for (int length = 2; length <= n; length++) {
        for (int i = 0; i <= n - length; i++) {
            int j = i + length - 1;
            dp[i][j] = INT_MAX;

            int totalFreq = sum(freq, i, j);

            for (int r = i; r <= j; r++) {
                int leftCost = (r > i) ? dp[i][r - 1] : 0;
                int rightCost = (r < j) ? dp[r + 1][j] : 0;
                int cost = leftCost + rightCost + totalFreq;
                if (cost < dp[i][j]) {
                    dp[i][j] = cost;
                }
            }
        }
    }

    return dp[0][n - 1];
}

int main() {
    int n1 = 3;
    printf("\u041E\u0440\u043E\u043B\u0442: n = %d\n", n1);
    printf("\u0413\u0430\u0440\u0430\u043B\u0442: %d\n", numTrees(n1));

    int keys[] = {10, 12, 20};
    int freq[] = {34, 8, 50};
    int n2 = sizeof(keys) / sizeof(keys[0]);

    int minCost = optimalBST(keys, freq, n2);
    printf("OBST-\u0438\u0439\u043D \u0445\u0430\u043C\u0433\u0438\u0439\u043D \u0431\u0430\u0433\u0430 \u0437\u0430\u0440\u0434\u0430\u043B: %d\n", minCost);

    return 0;
}