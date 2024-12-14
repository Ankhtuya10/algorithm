#include <stdio.h>
#include <stdlib.h>

void sort(int* nums, int numsSize) {
    for (int i = 0; i < numsSize - 1; i++) {
        for (int j = 0; j < numsSize - i - 1; j++) {
            if (nums[j] > nums[j + 1]) {
                int temp = nums[j];
                nums[j] = nums[j + 1];
                nums[j + 1] = temp;
            }
        }
    }
}

int** threeSum(int* nums, int numsSize, int* returnSize, int** returnColumnSizes) {
    sort(nums, numsSize);

    int maxTriplets = numsSize * (numsSize - 1) / 2; 
    int** result = malloc(maxTriplets * sizeof(int*));
    *returnColumnSizes = malloc(maxTriplets * sizeof(int));
    *returnSize = 0;

    for (int i = 0; i < numsSize; i++) {
        if (i > 0 && nums[i] == nums[i - 1]) {
            continue; 
        }

        int left = i + 1, right = numsSize - 1;
        while (left < right) {
            int summation = nums[i] + nums[left] + nums[right];

            if (summation == 0) {
                result[*returnSize] = malloc(3 * sizeof(int));
                result[*returnSize][0] = nums[i];
                result[*returnSize][1] = nums[left];
                result[*returnSize][2] = nums[right];
                (*returnColumnSizes)[*returnSize] = 3;
                (*returnSize)++;

                left++;
                right--;

                while (left < right && nums[left] == nums[left - 1]) {
                    left++; 
                }
                while (left < right && nums[right] == nums[right + 1]) {
                    right--; 
                }
            } else if (summation < 0) {
                left++;
            } else {
                right--;
            }
        }
    }

    return result;
}

int main() {
    int nums[] = {-1, 0, 1, 2, -1, -4};
    int numsSize = 6;
    int returnSize;
    int* returnColumnSizes;
    int** result = threeSum(nums, numsSize, &returnSize, &returnColumnSizes);

    for (int i = 0; i < returnSize; i++) {
        printf("[");
        for (int j = 0; j < returnColumnSizes[i]; j++) {
            printf("%d%s", result[i][j], (j == returnColumnSizes[i] - 1) ? "" : ", ");
        }
        printf("]\n");
        free(result[i]);
    }

    free(result);
    free(returnColumnSizes);

    return 0;
}