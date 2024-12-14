class Solution:
    def sortArray(self, nums):
        if len(nums) <= 1:
            return nums
        
        return self.merge_sort(nums, 0, len(nums) - 1)

    def merge_sort(self, arr, left, right):
        if left >= right:
            return [arr[left]]
        
        # Divide
        mid = left + (right - left) // 2
        left_half = self.merge_sort(arr, left, mid)
        right_half = self.merge_sort(arr, mid + 1, right)
        
        # Conquer
        return self.merge(left_half, right_half)

    def merge(self, left, right):
        left_index, right_index = 0, 0
        sorted_list = []

        # Merge
        while left_index < len(left) and right_index < len(right):
            if left[left_index] <= right[right_index]:
                sorted_list.append(left[left_index])
                left_index += 1
            else:
                sorted_list.append(right[right_index])
                right_index += 1

        sorted_list.extend(left[left_index:])
        sorted_list.extend(right[right_index:])

        return sorted_list

if __name__ == "__main__":
    sol = Solution()
    nums1 = [5, 2, 3, 1]
    nums2 = [5, 1, 1, 2, 0, 0]

    sorted1 = sol.sortArray(nums1)
    sorted2 = sol.sortArray(nums2)

    print(sorted1)  
    print(sorted2) 