public class Solution {
    public int maxProfit(int[] prices) {
        int totalProfit = 0;

        for (int i = 0; i < prices.length - 1; i++) {
            // Хэрвээ маргаашийн үнэ өнөөдрийнхөөс өндөр байвал ашиг олж болно
            if (prices[i] < prices[i + 1]) {
                // Ашгийг нэмнэ: маргаашийн үнэ - өнөөдрийн үнэ
                totalProfit += prices[i + 1] - prices[i];
            }
        }

        return totalProfit; // Нийт ашгийг буцаана
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // Жишээ 1: Үнийн дараалал
        int[] prices1 = {7, 1, 5, 3, 6, 4};
        System.out.println(solution.maxProfit(prices1));  // Гаралт: 7

        // Жишээ 2: Байнга өссөн үнэ
        int[] prices2 = {1, 2, 3, 4, 5};
        System.out.println(solution.maxProfit(prices2));  // Гаралт: 4

        // Жишээ 3: Байнга буурсан үнэ
        int[] prices3 = {7, 6, 4, 3, 1};
        System.out.println(solution.maxProfit(prices3));  // Гаралт: 0
    }
}
