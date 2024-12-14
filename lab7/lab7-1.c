#include <stdio.h>
#include <stdlib.h>

typedef struct {
    double value;
    double weight;
    double ratio;
} Item;

int compare(const void *a, const void *b) {
    Item *itemA = (Item *)a;
    Item *itemB = (Item *)b;
    if (itemB->ratio > itemA->ratio) return 1;
    if (itemB->ratio < itemA->ratio) return -1;
    return 0;
}

double fractional_knapsack(Item items[], int n, double capacity) {
    qsort(items, n, sizeof(Item), compare);

    double total_value = 0.0;
    for (int i = 0; i < n; i++) {
        if (capacity >= items[i].weight) {
            capacity -= items[i].weight;
            total_value += items[i].value;
        } else {
            total_value += items[i].value * (capacity / items[i].weight);
            break;
        }
    }

    return total_value;
}

int main() {
    int n;
    printf("Enter the number of items: ");
    scanf("%d", &n);

    Item *items = (Item *)malloc(n * sizeof(Item));

    for (int i = 0; i < n; i++) {
        printf("Enter value and weight of item %d (separated by space): ", i + 1);
        scanf("%lf %lf", &items[i].value, &items[i].weight);
        items[i].ratio = items[i].value / items[i].weight;
    }

    double capacity;
    printf("Enter the capacity of the knapsack: ");
    scanf("%lf", &capacity);

    double max_value = fractional_knapsack(items, n, capacity);
    printf("Maximum value in knapsack = %.2lf\n", max_value);

    free(items);
    return 0;
}