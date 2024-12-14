import java.util.HashMap;
import java.util.Map;

public class Solution {
    public int leastInterval(char[] tasks, int n) {
        Map<Character, Integer> frequencyMap = new HashMap<>();
        for (char task : tasks) {
            frequencyMap.put(task, frequencyMap.getOrDefault(task, 0) + 1);
        }

        int maxFrequency = 0; 
        int maxCount = 0; 
        for (int freq : frequencyMap.values()) {
            if (freq > maxFrequency) {
                maxFrequency = freq;
                maxCount = 1; 
            } else if (freq == maxFrequency) {
                maxCount++; 
            }
        }

        int totalSlots = (maxFrequency - 1) * (n + 1) + maxCount;

        return Math.max(totalSlots, tasks.length);
    }

    public static void main(String[] args) {
        Solution solution = new Solution();

        char[] tasks1 = {'A', 'A', 'A', 'B', 'B', 'B'};
        int n1 = 2;
        System.out.println(solution.leastInterval(tasks1, n1)); 

        char[] tasks2 = {'A', 'C', 'A', 'B', 'D', 'B'};
        int n2 = 1;
        System.out.println(solution.leastInterval(tasks2, n2)); 

        char[] tasks3 = {'A', 'A', 'A', 'B', 'B', 'B'};
        int n3 = 3;
        System.out.println(solution.leastInterval(tasks3, n3)); 
    }
}
