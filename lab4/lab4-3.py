class Solution:
    def __init__(self):
        self.memo = {}
    
    def coinChange(self, coins, amount):
        if amount == 0:
            return 0
        
        result = self.findMinCoins(coins, amount)
        return result if result != float('inf') else -1
    
    def findMinCoins(self, coins, amount):
       
        if amount == 0:
            return 0
        
        if amount < 0:
            return float('inf')
        
        if amount in self.memo:
            return self.memo[amount]
        
        min_coins = float('inf')
        
        for coin in coins:
            num_coins = self.findMinCoins(coins, amount - coin)
            if num_coins != float('inf'):
                min_coins = min(min_coins, num_coins + 1)
        self.memo[amount] = min_coins
        
        return self.memo[amount]

solution = Solution()
coins = [1, 2, 5]
amount = 11
print(solution.coinChange(coins, amount))  

coins = [2]
amount = 3
print(solution.coinChange(coins, amount))  

coins = [1]
amount = 0
print(solution.coinChange(coins, amount))  
