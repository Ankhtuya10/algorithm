def potential_function(D):
    return len(D)  # Потенциал функцийг дарааллын уртаар тодорхойлъё.

def amortized_cost(n):
    D = []
    total_cost = 0
    for i in range(n):
        if i % 2 == 0:  # Push үйлдэл
            D.append(i)
            total_cost += 1 + potential_function(D)
        else:  # Pop үйлдэл
            if D:
                D.pop()
                total_cost += 1 - potential_function(D)
    average_cost = total_cost / n
    return average_cost

n = 10
print(f"Amortized cost for {n} operations: {amortized_cost(n)}")
