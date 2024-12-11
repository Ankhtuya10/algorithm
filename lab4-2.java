public class Solution {
    public int minCostClimbingStairs(int[] cost) {
        int n = cost.length;
        
        // Handle base cases
        if (n == 2) {
            return Math.min(cost[0], cost[1]);
        }
        
        // Initialize the dp array
        int[] dp = new int[n];
        
        // Base cases
        dp[0] = cost[0];
        dp[1] = cost[1];
        
        // Fill the dp array
        for (int i = 2; i < n; i++) {
            dp[i] = Math.min(dp[i-1], dp[i-2]) + cost[i];
        }
        
        // Return the minimum cost to reach the top
        return Math.min(dp[n-1], dp[n-2]);
    }

    // Example usage
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] cost1 = {10, 15, 20};
        int[] cost2 = {1, 100, 1, 1, 1, 100, 1, 1, 100, 1};
        System.out.println(solution.minCostClimbingStairs(cost1));  // Output: 15
        System.out.println(solution.minCostClimbingStairs(cost2));  // Output: 6
    }
}