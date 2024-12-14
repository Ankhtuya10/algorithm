#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAX_TASKS 26

int leastInterval(char* tasks, int tasksSize, int n) {
    int frequencyMap[MAX_TASKS] = {0};

    for (int i = 0; i < tasksSize; i++) {
        frequencyMap[tasks[i] - 'A']++;
    }
    int maxFrequency = 0;
    int maxCount = 0;
    for (int i = 0; i < MAX_TASKS; i++) {
        if (frequencyMap[i] > maxFrequency) {
            maxFrequency = frequencyMap[i];
            maxCount = 1;
        } else if (frequencyMap[i] == maxFrequency) {
            maxCount++;
        }
    }

    int totalSlots = (maxFrequency - 1) * (n + 1) + maxCount;

    return totalSlots > tasksSize ? totalSlots : tasksSize;
}

int main() {
    char tasks1[] = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n1 = 2;
    printf("%d\n", leastInterval(tasks1, sizeof(tasks1) / sizeof(tasks1[0]), n1));

    char tasks2[] = {'A', 'C', 'A', 'B', 'D', 'B'};
    int n2 = 1;
    printf("%d\n", leastInterval(tasks2, sizeof(tasks2) / sizeof(tasks2[0]), n2));

    char tasks3[] = {'A', 'A', 'A', 'B', 'B', 'B'};
    int n3 = 3;
    printf("%d\n", leastInterval(tasks3, sizeof(tasks3) / sizeof(tasks3[0]), n3));

    return 0;
}