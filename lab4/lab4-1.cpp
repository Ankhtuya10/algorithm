#include <iostream>
#include <unordered_map>

class Solution {
private:
    std::unordered_map<int, int> memo;

public:
    int climbStairs(int n) {
        if (n == 0 || n == 1) {
            return 1;
        }
        
        if (memo.find(n) != memo.end()) {
            return memo[n];
        }

        memo[n] = climbStairs(n - 1) + climbStairs(n - 2);
        return memo[n];
    }
};

int main() {
    Solution solution;

    int n1 = 3;
    std::cout << "Number of ways to climb " << n1 << " steps: " << solution.climbStairs(n1) << std::endl;

    int n2 = 2;
    std::cout << "Number of ways to climb " << n2 << " steps: " << solution.climbStairs(n2) << std::endl;

    return 0;
}