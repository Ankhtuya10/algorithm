#include <iostream>
#include <vector>
#include <unordered_map>
#include <climits>

class Solution {
public:
    std::unordered_map<int, int> memo;

    int coinChange(std::vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        int result = findMinCoins(coins, amount);
        return result != INT_MAX ? result : -1;
    }

private:
    int findMinCoins(std::vector<int>& coins, int amount) {
        if (amount == 0) {
            return 0;
        }

        if (amount < 0) {
            return INT_MAX;
        }

        if (memo.find(amount) != memo.end()) {
            return memo[amount];
        }

        int min_coins = INT_MAX;

        for (int coin : coins) {
            int num_coins = findMinCoins(coins, amount - coin);
            if (num_coins != INT_MAX) {
                min_coins = std::min(min_coins, num_coins + 1);
            }
        }

        memo[amount] = min_coins;
        return memo[amount];
    }
};

int main() {
    Solution solution;

    std::vector<int> coins1 = {1, 2, 5};
    int amount1 = 11;
    std::cout << solution.coinChange(coins1, amount1) << std::endl;

    std::vector<int> coins2 = {2};
    int amount2 = 3;
    std::cout << solution.coinChange(coins2, amount2) << std::endl;

    std::vector<int> coins3 = {1};
    int amount3 = 0;
    std::cout << solution.coinChange(coins3, amount3) << std::endl;

    return 0;
}