class Solution:
    def minCostClimbingStairs(self, cost):
        n = len(cost)
        if n == 2:
            return min(cost[0], cost[1])

        dp = [0] * n
        dp[0] = cost[0]
        dp[1] = cost[1]

        for i in range(2, n):
            dp[i] = min(dp[i - 1], dp[i - 2]) + cost[i]

        return min(dp[n - 1], dp[n - 2])

if __name__ == "__main__":
    solution = Solution()
    cost1 = [10, 15, 20]
    cost2 = [1, 100, 1, 1, 1, 100, 1, 1, 100, 1]
    print(solution.minCostClimbingStairs(cost1))  
    print(solution.minCostClimbingStairs(cost2))  