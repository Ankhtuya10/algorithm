#include <stdio.h>
#include <stdlib.h>

int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    
    typedef struct {
        int key;   
        int value; 
    } HashMap;

    HashMap* map = malloc(numsSize * sizeof(HashMap));
    int mapSize = 0;

    int findInMap(HashMap* map, int mapSize, int key) {
        for (int i = 0; i < mapSize; i++) {
            if (map[i].key == key) {
                return map[i].value;
            }
        }
        return -1; 
    }

    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        int complementIndex = findInMap(map, mapSize, complement);

        if (complementIndex != -1) {
            
            int* result = malloc(2 * sizeof(int));
            result[0] = complementIndex;
            result[1] = i;
            *returnSize = 2;
            free(map); 
            return result;
        }

        
        map[mapSize].key = nums[i];
        map[mapSize].value = i;
        mapSize++;
    }

    *returnSize = 0; 
    free(map); 
    return NULL;
}

int main() {
    int nums[] = {2, 7, 11, 15};
    int target = 9;
    int returnSize;
    int* result = twoSum(nums, 4, target, &returnSize);

    if (returnSize == 2) {
        printf("Indices: [%d, %d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No solution found.\n");
    }

    return 0;
}