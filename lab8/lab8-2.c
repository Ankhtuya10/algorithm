#include <stdio.h>
#include <stdbool.h>
#include <math.h>

int countPrimes(int n) {
    if (n < 2) {
        return 0;
    }
    bool is_prime[n + 1];
    for (int i = 0; i <= n; i++) {
        is_prime[i] = true;
    }
    is_prime[0] = is_prime[1] = false;
    
    for (int i = 2; i <= sqrt(n); i++) {
        if (is_prime[i]) {
            for (int j = i * i; j <= n; j += i) {
                is_prime[j] = false;
            }
        }
    }
    
    int count = 0;
    for (int i = 2; i <= n; i++) {
        if (is_prime[i]) {
            count++;
        }
    }
    
    return count;
}

int main() {
    int n = 18;
    printf("%d\n", countPrimes(n));  
    return 0;
}