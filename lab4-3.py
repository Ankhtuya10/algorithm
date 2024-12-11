class Solution:
    def __init__(self):
        # A memoization dictionary to store already computed results
        self.memo = {}
    
    def coinChange(self, coins, amount):
        # If the amount is zero, no coins are needed
        if amount == 0:
            return 0
        
        # Start recursive function to find minimum coins
        result = self.findMinCoins(coins, amount)
        
        # If the result is a large number (impossible to make change), return -1
        return result if result != float('inf') else -1
    
    def findMinCoins(self, coins, amount):
        # If the amount is zero, no more coins are needed
        if amount == 0:
            return 0
        
        # If the amount is negative, return infinity (impossible situation)
        if amount < 0:
            return float('inf')
        
        # If we've already computed the result for this amount, return it
        if amount in self.memo:
            return self.memo[amount]
        
        # Initialize the minimum number of coins to infinity
        min_coins = float('inf')
        
        # Try every coin and recursively find the minimum number of coins
        for coin in coins:
            num_coins = self.findMinCoins(coins, amount - coin)
            if num_coins != float('inf'):
                min_coins = min(min_coins, num_coins + 1)
        
        # Memoize the result for this amount
        self.memo[amount] = min_coins
        
        return self.memo[amount]

# Example usage:
solution = Solution()
coins = [1, 2, 5]
amount = 11
print(solution.coinChange(coins, amount))  # Output: 3 (5 + 5 + 1)

coins = [2]
amount = 3
print(solution.coinChange(coins, amount))  # Output: -1 (impossible to make 3)

coins = [1]
amount = 0
print(solution.coinChange(coins, amount))  # Output: 0 (no coins needed)
