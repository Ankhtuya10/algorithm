#include <iostream>
#include <vector>

class Solution {
public:
    int majorityElement(std::vector<int>& nums) {
        return majorityElementRec(nums, 0, nums.size() - 1);
    }

private:
    int majorityElementRec(std::vector<int>& nums, int start, int end) {
        if (start == end) {
            return nums[start];
        }

        int mid = start + (end - start) / 2;
        int leftMajority = majorityElementRec(nums, start, mid);
        int rightMajority = majorityElementRec(nums, mid + 1, end);

        if (leftMajority == rightMajority) {
            return leftMajority;
        }

        int leftCount = countInRange(nums, leftMajority, start, end);
        int rightCount = countInRange(nums, rightMajority, start, end);

        return leftCount > rightCount ? leftMajority : rightMajority;
    }

    int countInRange(std::vector<int>& nums, int num, int start, int end) {
        int count = 0;
        for (int i = start; i <= end; ++i) {
            if (nums[i] == num) {
                ++count;
            }
        }
        return count;
    }
};

int main() {
    Solution sol;

    std::vector<int> nums1 = {3, 2, 3};
    std::cout << sol.majorityElement(nums1) << std::endl;

    std::vector<int> nums2 = {2, 2, 1, 1, 1, 2, 2};
    std::cout << sol.majorityElement(nums2) << std::endl;

    return 0;
}