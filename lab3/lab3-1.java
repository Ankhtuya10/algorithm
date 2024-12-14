class Solution {
    public int majorityElement(int[] nums) {
        return majorityElementRec(nums, 0, nums.length - 1);
    }

    private int majorityElementRec(int[] nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }

        int mid = (start + end) / 2;
        int leftMajority = majorityElementRec(nums, start, mid);
        int rightMajority = majorityElementRec(nums, mid + 1, end);

        if (leftMajority == rightMajority) {
            return leftMajority;
        }

        int leftCount = countInRange(nums, leftMajority, start, end);
        int rightCount = countInRange(nums, rightMajority, start, end);

        return leftCount > rightCount ? leftMajority : rightMajority;
    }

    private int countInRange(int[] nums, int num, int start, int end) {
        int count = 0;
        for (int i = start; i <= end; i++) {
            if (nums[i] == num) {
                count++;
            }
        }
        return count;
    }

    public static void main(String[] args) {
        Solution sol = new Solution();

        System.out.println(sol.majorityElement(new int[] {3, 2, 3}));  
        System.out.println(sol.majorityElement(new int[] {2, 2, 1, 1, 1, 2, 2}));  
    }
}