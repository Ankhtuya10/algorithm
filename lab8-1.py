def coinChange(coins, amount):
    # Дүн бүрийн хувьд dp массивыг 'хязгааргүй' гэж анхдагч байдлаар тодорхойлно, зөвхөн dp[0] = 0 гэж авна
    dp = [float('inf')] * (amount + 1)
    dp[0] = 0
    
    # Зоос бүрээр давталт хийнэ
    for coin in coins:
        for i in range(coin, amount + 1):
            # dp[i] утгыг одоогийн утга болон (dp[i - coin] + 1)-ийн бага утга гэж шинэчилнэ
            dp[i] = min(dp[i], dp[i - coin] + 1)
    
    # Хэрэв dp[amount] 'хязгааргүй' хэвээр байвал -1 (боломжгүй) гэж буцаана
    return dp[amount] if dp[amount] != float('inf') else -1

# Жишээ ашиглалт:
coins = [1, 2, 5]
amount = 11
print(coinChange(coins, amount))  # Гаралт: 3 (5 + 5 + 1)
