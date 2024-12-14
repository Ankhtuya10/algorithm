#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

void insertion_sort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void merge(int arr[], int left, int mid, int right) {
    int n1 = mid - left + 1;
    int n2 = right - mid;

    int *L = (int *)malloc(n1 * sizeof(int));
    int *R = (int *)malloc(n2 * sizeof(int));

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            arr[k] = L[i];
            i++;
        } else {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        arr[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        arr[k] = R[j];
        j++;
        k++;
    }

    free(L);
    free(R);
}

void merge_sort(int arr[], int left, int right) {
    if (left < right) {
        int mid = left + (right - left) / 2;

        merge_sort(arr, left, mid);
        merge_sort(arr, mid + 1, right);

        merge(arr, left, mid, right);
    }
}

int recursive_binary_search(int arr[], int low, int high, int x) {
    if (high >= low) {
        int mid = low + (high - low) / 2;

        if (arr[mid] == x)
            return mid;
        else if (arr[mid] > x)
            return recursive_binary_search(arr, low, mid - 1, x);
        else
            return recursive_binary_search(arr, mid + 1, high, x);
    }
    return -1;
}

int find_max(int arr[], int low, int high) {
    if (low == high)
        return arr[low];

    int mid = low + (high - low) / 2;
    int max_left = find_max(arr, low, mid);
    int max_right = find_max(arr, mid + 1, high);

    return (max_left > max_right) ? max_left : max_right;
}

void test_insertion_sort() {
    int arr1[] = {5, 2, 9, 1, 5, 6};
    int sorted1[] = {1, 2, 5, 5, 6, 9};
    insertion_sort(arr1, 6);
    for (int i = 0; i < 6; i++)
        assert(arr1[i] == sorted1[i]);

    int arr2[] = {};
    insertion_sort(arr2, 0);
    assert(1);

    int arr3[] = {1};
    insertion_sort(arr3, 1);
    assert(arr3[0] == 1);
}

void test_merge_sort() {
    int arr1[] = {5, 2, 9, 1, 5, 6};
    int sorted1[] = {1, 2, 5, 5, 6, 9};
    merge_sort(arr1, 0, 5);
    for (int i = 0; i < 6; i++)
        assert(arr1[i] == sorted1[i]);

    int arr2[] = {1, 2, 3};
    int sorted2[] = {1, 2, 3};
    merge_sort(arr2, 0, 2);
    for (int i = 0; i < 3; i++)
        assert(arr2[i] == sorted2[i]);

    int arr3[] = {};
    merge_sort(arr3, 0, -1);
    assert(1);
}

void test_recursive_binary_search() {
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    assert(recursive_binary_search(arr, 0, 6, 4) == 3);
    assert(recursive_binary_search(arr, 0, 6, 10) == -1);
}

void test_find_max() {
    int arr1[] = {1, 2, 3, 4, 5};
    assert(find_max(arr1, 0, 4) == 5);

    int arr2[] = {5, 1, 2, 3, 4};
    assert(find_max(arr2, 0, 4) == 5);

    int arr3[] = {10};
    assert(find_max(arr3, 0, 0) == 10);
}

int main() {
    test_insertion_sort();
    test_merge_sort();
    test_recursive_binary_search();
    test_find_max();

    printf("All tests passed.\n");
    return 0;
}