public class Solution {
    public int maxProfit(int[] prices) {
        int totalProfit = 0;

        for (int i = 0; i < prices.length - 1; i++) {
            if (prices[i] < prices[i + 1]) {
                totalProfit += prices[i + 1] - prices[i];
            }
        }

        return totalProfit; 
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        int[] prices1 = {7, 1, 5, 3, 6, 4};
        System.out.println(solution.maxProfit(prices1));  

        int[] prices2 = {1, 2, 3, 4, 5};
        System.out.println(solution.maxProfit(prices2));  

        int[] prices3 = {7, 6, 4, 3, 1};
        System.out.println(solution.maxProfit(prices3));  
    }
}
