def max_profit(prices):
    total_profit = 0  # Эцсийн ашиг
    # Хөдөлж буй үнийн массивыг шалгах
    for i in range(1, len(prices)):  # 1-р индексээс эхлэн (2 дахь өдөр)
        # Хэрэв өнөөдрийн үнэ өчигдрийн үнийнхээс илүү бол
        if prices[i] > prices[i - 1]:
            # Энэ худалдааны ашиг (өнөөдрийн үнэ - өчигдрийн үнэ) нэмэх
            total_profit += prices[i] - prices[i - 1]
    
    return total_profit  # Нийт ашиг

# Жишээ ашиглалт:
prices1 = [7, 1, 5, 3, 6, 4]
print(max_profit(prices1))  # Гаралт: 7

prices2 = [1, 2, 3, 4, 5]
print(max_profit(prices2))  # Гаралт: 4

prices3 = [7, 6, 4, 3, 1]
print(max_profit(prices3))  # Гаралт: 0
