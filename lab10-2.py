def simulate_stack_operations(n, k):
    total_cost = 0
    for i in range(1, n + 1):
        if i % k == 0:  # k бүрийн дараа нөөцөлж хуулбарлах
            total_cost += k  # Нөөцлөх өртөг k
        else:
            total_cost += 1  # Ердийн Push/Pop өртөг
    return total_cost

n = 16
k = 4
print(f"Total cost for {n} operations with backup every {k}: {simulate_stack_operations(n, k)}")
