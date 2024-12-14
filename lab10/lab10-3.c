#include <stdio.h>

int potential_function(int D_size) {
    return D_size; 
}

double amortized_cost(int n) {
    int D[n];
    int D_size = 0;
    double total_cost = 0;

    for (int i = 0; i < n; i++) {
        if (i % 2 == 0) {
            D[D_size++] = i;  
            total_cost += 1 + potential_function(D_size);
        } else {
            if (D_size > 0) {
                D_size--;  
                total_cost += 1 - potential_function(D_size);
            }
        }
    }

    double average_cost = total_cost / n;
    return average_cost;
}

int main() {
    int n = 10;
    printf("Amortized cost for %d operations: %f\n", n, amortized_cost(n));
    return 0;
}