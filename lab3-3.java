import java.util.ArrayList;
import java.util.List;

public class Solution {
    
    public int[] sortArray(int[] nums) {
        if (nums.length <= 1) {
            return nums;
        }
        
        return mergeSort(nums, 0, nums.length - 1);
    }
    
    private int[] mergeSort(int[] arr, int left, int right) {
        if (left >= right) {
            return new int[] {arr[left]};
        }
        
        // Divide
        int mid = left + (right - left) / 2;
        int[] leftHalf = mergeSort(arr, left, mid);
        int[] rightHalf = mergeSort(arr, mid + 1, right);
        
        // Conquer
        return merge(leftHalf, rightHalf);
    }
    
    private int[] merge(int[] left, int[] right) {
        int leftIndex = 0, rightIndex = 0;
        int[] sortedList = new int[left.length + right.length];
        int sortedIndex = 0;
        
        // Merge
        while (leftIndex < left.length && rightIndex < right.length) {
            if (left[leftIndex] <= right[rightIndex]) {
                sortedList[sortedIndex++] = left[leftIndex++];
            } else {
                sortedList[sortedIndex++] = right[rightIndex++];
            }
        }
        
        // Append remaining elements
        while (leftIndex < left.length) {
            sortedList[sortedIndex++] = left[leftIndex++];
        }
        while (rightIndex < right.length) {
            sortedList[sortedIndex++] = right[rightIndex++];
        }
        
        return sortedList;
    }
    
    public static void main(String[] args) {
        Solution sol = new Solution();
        int[] nums1 = {5, 2, 3, 1};
        int[] nums2 = {5, 1, 1, 2, 0, 0};
        
        int[] sorted1 = sol.sortArray(nums1);
        int[] sorted2 = sol.sortArray(nums2);
        
        System.out.println(java.util.Arrays.toString(sorted1)); // Output: [1, 2, 3, 5]
        System.out.println(java.util.Arrays.toString(sorted2)); // Output: [0, 0, 1, 1, 2, 5]
    }
}