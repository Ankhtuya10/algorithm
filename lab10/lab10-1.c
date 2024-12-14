#include <stdio.h>

double aggregate_cost(int n) {
    double total_cost = 0;

    for (int i = 1; i <= n; i++) {
        if ((i & (i - 1)) == 0) {
            total_cost += i;  
        } else {
            total_cost += 1; 
        }
    }
    return total_cost / n;
}

int main() {
    int n = 16;
    printf("Average cost for %d operations: %.2f\n", n, aggregate_cost(n));
    return 0;
}