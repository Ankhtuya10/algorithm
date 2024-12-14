#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define MAX_STUDENTS 1000
#define MAX_BIKES 1000
typedef struct {
    int distance;
    int student_idx;
    int bike_idx;
} DistanceEntry;
int compare(const void *a, const void *b) {
    DistanceEntry *entryA = (DistanceEntry *)a;
    DistanceEntry *entryB = (DistanceEntry *)b;
    if (entryA->distance != entryB->distance) {
        return entryA->distance - entryB->distance;
    }
    if (entryA->student_idx != entryB->student_idx) {
        return entryA->student_idx - entryB->student_idx;
    }
    return entryA->bike_idx - entryB->bike_idx;
}
int* assignBikes(int students[][2], int numStudents, int bikes[][2], int numBikes) {
    DistanceEntry pq[MAX_STUDENTS * MAX_BIKES];
    int pqSize = 0;
    for (int i = 0; i < numStudents; i++) {
        for (int j = 0; j < numBikes; j++) {
            int distance = abs(students[i][0] - bikes[j][0]) + abs(students[i][1] - bikes[j][1]);
            pq[pqSize++] = (DistanceEntry){distance, i, j};
        }
    }
    qsort(pq, pqSize, sizeof(DistanceEntry), compare);
    int assignedStudents[MAX_STUDENTS] = {0};
    int assignedBikes[MAX_BIKES] = {0};
    int* result = (int*)malloc(numStudents * sizeof(int));
    for (int i = 0; i < numStudents; i++) {
        result[i] = -1;
    }
    for (int i = 0; i < pqSize; i++) {
        int studentIdx = pq[i].student_idx;
        int bikeIdx = pq[i].bike_idx;

        if (!assignedStudents[studentIdx] && !assignedBikes[bikeIdx]) {
            result[studentIdx] = bikeIdx;
            assignedStudents[studentIdx] = 1;
            assignedBikes[bikeIdx] = 1;
        }
    }

    return result;
}

int main() {
    int students[2][2] = {{0, 0}, {1, 1}};
    int bikes[3][2] = {{0, 1}, {4, 3}, {2, 1}};
    
    int *result = assignBikes(students, 2, bikes, 3);
    for (int i = 0; i < 2; i++) {
        printf("%d ", result[i]);
    }
    printf("\n");
    free(result);
    
    return 0;
}