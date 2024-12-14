#include <stdio.h>

int simulate_stack_operations(int n, int k) {
    int total_cost = 0;
    for (int i = 1; i <= n; i++) {
        if (i % k == 0) {
            total_cost += k;
        } else {
            total_cost += 1;
        }
    }
    return total_cost;
}

int main() {
    int n = 16;
    int k = 4;
    printf("Total cost for %d operations with backup every %d: %d\n", n, k, simulate_stack_operations(n, k));
    return 0;
}