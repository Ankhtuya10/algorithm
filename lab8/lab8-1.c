#include <stdio.h>
#include <limits.h>

int coinChange(int coins[], int coinsSize, int amount) {
    int dp[amount + 1];
    for (int i = 0; i <= amount; i++) {
        dp[i] = INT_MAX;
    }
    dp[0] = 0;
    for (int i = 0; i < coinsSize; i++) {
        for (int j = coins[i]; j <= amount; j++) {
            if (dp[j - coins[i]] != INT_MAX) {
                dp[j] = (dp[j] < dp[j - coins[i]] + 1) ? dp[j] : dp[j - coins[i]] + 1;
            }
        }
    }
    return dp[amount] == INT_MAX ? -1 : dp[amount];
}

int main() {
    int coins[] = {1, 2, 5};
    int amount = 11;
    int coinsSize = sizeof(coins) / sizeof(coins[0]);
    
    int result = coinChange(coins, coinsSize, amount);
    printf("%d\n", result);  // Output: 3
    
    return 0;
}