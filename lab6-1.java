public class Solution {
    // 1. Тусгай BST-ийг тоолох функц
    public int numTrees(int n) {
        // dp[i] нь i тооны зангилаатай BST-үүдийн тоог хадгална
        int[] dp = new int[n + 1];
        dp[0] = 1; // Суурь тохиолдол: хоосон мод
        dp[1] = 1; // Суурь тохиолдол: нэг зангилаатай мод

        // DP хүснэгтийг бөглөх
        for (int nodes = 2; nodes <= n; nodes++) { // 2-с эхлээд n хүртэл зангилаанууд
            for (int root = 1; root <= nodes; root++) { // Тухайн зангилааг үндэс болгох
                int leftTrees = dp[root - 1]; // Зүүн модны BST-үүдийн тоо
                int rightTrees = dp[nodes - root]; // Баруун модны BST-үүдийн тоо
                dp[nodes] += leftTrees * rightTrees; // Тухайн үндэстэй нийт моднууд
            }
        }
        return dp[n];
    }

    // 2. OBST-ийн хамгийн бага хайлтын зардал тооцох функц
    public int optimalBST(int[] keys, int[] freq) {
        int n = keys.length;
        // dp[i][j] нь keys[i]-ээс keys[j] хүртэл хамгийн бага хайлтын зардлыг хадгална
        int[][] dp = new int[n][n];

        // Нэг түлхүүртэй модны зардлыг диагональ бөглөх
        for (int i = 0; i < n; i++) {
            dp[i][i] = freq[i]; // Нэг зангилааны зардал нь түүний давтамж
        }

        // Зардлыг 2-с n хүртэл урттай гинжэнд тооцоолох
        for (int length = 2; length <= n; length++) {
            for (int i = 0; i <= n - length; i++) {
                int j = i + length - 1; // Гинжний төгсгөлийн индекс
                dp[i][j] = Integer.MAX_VALUE; // Их утгаар эхлүүлэх

                // i-с j хүртэлх давтамжуудын нийлбэр
                int totalFreq = sum(freq, i, j);

                // Түлхүүр бүрийг үндэс болгох
                for (int r = i; r <= j; r++) {
                    int leftCost = (r > i) ? dp[i][r - 1] : 0; // Зүүн модны зардал
                    int rightCost = (r < j) ? dp[r + 1][j] : 0; // Баруун модны зардал
                    int cost = leftCost + rightCost + totalFreq; // Нийт зардал
                    dp[i][j] = Math.min(dp[i][j], cost); // Хамгийн бага зардлыг хадгалах
                }
            }
        }

        return dp[0][n - 1]; // Бүх модны хамгийн бага зардал
    }

    // Давтамжийг тооцох туслах функц
    private int sum(int[] freq, int start, int end) {
        int total = 0;
        for (int i = start; i <= end; i++) {
            total += freq[i];
        }
        return total;
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        // numTrees функцийн жишээ
        int n1 = 3;
        System.out.println("Оролт: n = " + n1);
        System.out.println("Гаралт: " + solution.numTrees(n1)); // Гаралт: 5

        // optimalBST функцийн жишээ
        int[] keys = {10, 12, 20};
        int[] freq = {34, 8, 50};

        int minCost = solution.optimalBST(keys, freq);
        System.out.println("OBST-ийн хамгийн бага зардал: " + minCost);
    }
}
