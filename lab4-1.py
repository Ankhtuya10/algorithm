class Solution:
    def __init__(self):
        # A memoization dictionary to store already computed results
        self.memo = {}
    
    def climbStairs(self, n):
        # Base cases
        if n == 0 or n == 1:
            return 1
        
        # Check if we have already computed ways for this n
        if n in self.memo:
            return self.memo[n]
        
        # Recursively compute ways for n-1 and n-2, and store the result
        self.memo[n] = self.climbStairs(n-1) + self.climbStairs(n-2)
        
        return self.memo[n]

# Example usage:
solution = Solution()
n = 3
print(solution.climbStairs(n))  # Output: 3

n = 2
print(solution.climbStairs(n))  # Output: 2
