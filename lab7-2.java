import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int leastInterval(char[] tasks, int n) {
        // 1-р алхам: Даалгавруудын давтамжийг тоолно
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char task : tasks) {
            frequencyMap.put(task, frequencyMap.getOrDefault(task, 0) + 1);
        }

        // 2-р алхам: Хамгийн их давтамжийг олох
        int maxFrequency = 0; // Хамгийн их давтамж
        int maxCount = 0; // Хамгийн их давтамжтай даалгаврын тоо
        for (int freq : frequencyMap.values()) {
            if (freq > maxFrequency) {
                maxFrequency = freq;
                maxCount = 1; // Хамгийн их давтамжтай даалгаврын тоог эхлүүлнэ
            } else if (freq == maxFrequency) {
                maxCount++; // Хамгийн их давтамжтай даалгаврын тоог нэмнэ
            }
        }

        // 3-р алхам: Интервалуудын тоог тооцоолох
        // Нийт завсар = (хамгийн их давтамж - 1) * (завсарлага n + 1) + хамгийн их тоотой даалгавар
        int totalSlots = (maxFrequency - 1) * (n + 1) + maxCount;

        // 4-р алхам: Нийт завсар болон даалгаврын уртаас хамгийн ихийг буцаана
        return Math.max(totalSlots, tasks.length);
    }

    public static void main(String[] args) {
        // Жишээ тестүүд
        Solution solution = new Solution();

        char[] tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
        int n1 = 2;
        System.out.println(solution.leastInterval(tasks1, n1)); // Гаралт: 8

        char[] tasks2 = {'A', 'C', 'A', 'B', 'D', 'B'};
        int n2 = 1;
        System.out.println(solution.leastInterval(tasks2, n2)); // Гаралт: 6

        char[] tasks3 = {'A', 'A', 'A', 'B', 'B', 'B'};
        int n3 = 3;
        System.out.println(solution.leastInterval(tasks3, n3)); // Гаралт: 10
    }
}
