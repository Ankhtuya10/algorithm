public class Solution {
    public int numTrees(int n) {
        int[] dp = new int[n + 1];
        dp[0] = 1; 
        dp[1] = 1; 

        for (int nodes = 2; nodes <= n; nodes++) { 
            for (int root = 1; root <= nodes; root++) { 
                int leftTrees = dp[root - 1]; 
                int rightTrees = dp[nodes - root]; 
                dp[nodes] += leftTrees * rightTrees; 
            }
        }
        return dp[n];
    }

    public int optimalBST(int[] keys, int[] freq) {
        int n = keys.length;
        
        int[][] dp = new int[n][n];

        for (int i = 0; i < n; i++) {
            dp[i][i] = freq[i]; 
        }

        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1; 
                dp[i][j] = Integer.MAX_VALUE; 

                int totalFreq = sum(freq, i, j);

                for (int r = i; r <= j; r++) {
                    int leftCost = (r > i) ? dp[i][r - 1] : 0; 
                    int rightCost = (r < j) ? dp[r + 1][j] : 0; 
                    int cost = leftCost + rightCost + totalFreq; 
                    dp[i][j] = Math.min(dp[i][j], cost); 
                }
            }
        }

        return dp[0][n - 1]; 
    }

    private int sum(int[] freq, int start, int end) {
        int total = 0;
        for (int i = start; i <= end; i++) {
            total += freq[i];
        }
        return total;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        int n1 = 3;
        System.out.println("Оролт: n = " + n1);
        System.out.println("Гаралт: " + solution.numTrees(n1)); 

        int[] keys = {10, 12, 20};
        int[] freq = {34, 8, 50};

        int minCost = solution.optimalBST(keys, freq);
        System.out.println("OBST-ийн хамгийн бага зардал: " + minCost);
    }
}
