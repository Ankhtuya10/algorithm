public class Solution {
    public int rob(int[] nums) {
        int n = nums.length;
        
        // Handle base cases
        if (n == 0) {
            return 0;
        }
        if (n == 1) {
            return nums[0];
        }
        if (n == 2) {
            return Math.max(nums[0], nums[1]);
        }
        
        // Initialize the DP array
        int[] dp = new int[n];
        dp[0] = nums[0];
        dp[1] = Math.max(nums[0], nums[1]);
        
        // Fill the DP array
        for (int i = 2; i < n; i++) {
            dp[i] = Math.max(dp[i-1], dp[i-2] + nums[i]);
        }
        
        // Return the result
        return dp[n-1];
    }

    // Example usage
    public static void main(String[] args) {
        Solution solution = new Solution();
        int[] nums1 = {1, 2, 3, 1};
        int[] nums2 = {2, 7, 9, 3, 1};
        System.out.println(solution.rob(nums1));  // Output: 4
        System.out.println(solution.rob(nums2));  // Output: 12
    }
}