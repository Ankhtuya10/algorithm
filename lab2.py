def insertion_sort(arr):
    for i in range(1, len(arr)):
        key = arr[i]
        j = i - 1
        while j >= 0 and key < arr[j]:
            arr[j + 1] = arr[j]
            j -= 1
        arr[j + 1] = key
    return arr

def merge_sort(arr):
    if len(arr) > 1:
        mid = len(arr) // 2
        left_half = arr[:mid]
        right_half = arr[mid:]

        merge_sort(left_half)
        merge_sort(right_half)

        i = j = k = 0

        while i < len(left_half) and j < len(right_half):
            if left_half[i] < right_half[j]:
                arr[k] = left_half[i]
                i += 1
            else:
                arr[k] = right_half[j]
                j += 1
            k += 1

        while i < len(left_half):
            arr[k] = left_half[i]
            i += 1
            k += 1

        while j < len(right_half):
            arr[k] = right_half[j]
            j += 1
            k += 1
    return arr

def recursive_binary_search(arr, low, high, x):
    if high >= low:
        mid = (low + high) // 2
        if arr[mid] == x:
            return mid
        elif arr[mid] > x:
            return recursive_binary_search(arr, low, mid - 1, x)
        else:
            return recursive_binary_search(arr, mid + 1, high, x)
    else:
        return -1

def find_max(arr, low, high):
    if low == high:
        return arr[low]
    mid = (low + high) // 2
    max_left = find_max(arr, low, mid)
    max_right = find_max(arr, mid + 1, high)
    return max(max_left, max_right)

import unittest

class TestAlgorithms(unittest.TestCase):
    def test_insertion_sort(self):
        self.assertEqual(insertion_sort([5, 2, 9, 1, 5, 6]), [1, 2, 5, 5, 6, 9])
        self.assertEqual(insertion_sort([]), [])
        self.assertEqual(insertion_sort([1]), [1])

    def test_merge_sort(self):
        self.assertEqual(merge_sort([5, 2, 9, 1, 5, 6]), [1, 2, 5, 5, 6, 9])
        self.assertEqual(merge_sort([1, 2, 3]), [1, 2, 3])
        self.assertEqual(merge_sort([]), [])

    def test_recursive_binary_search(self):
        arr = [1, 2, 3, 4, 5, 6, 7]
        self.assertEqual(recursive_binary_search(arr, 0, len(arr) - 1, 4), 3)
        self.assertEqual(recursive_binary_search(arr, 0, len(arr) - 1, 10), -1)

    def test_find_max(self):
        self.assertEqual(find_max([1, 2, 3, 4, 5], 0, 4), 5)
        self.assertEqual(find_max([5, 1, 2, 3, 4], 0, 4), 5)
        self.assertEqual(find_max([10], 0, 0), 10)

if __name__ == '__main__':
    unittest.main()