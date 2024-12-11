import math

def aggregate_cost(n):
    total_cost = 0
    for i in range(1, n + 1):
        if (i & (i - 1)) == 0:  # i нь хоёрын зэрэг мөн эсэхийг шалгах
            total_cost += i
        else:
            total_cost += 1
    average_cost = total_cost / n
    return average_cost

n = 16
print(f"Average cost for {n} operations: {aggregate_cost(n)}")
