class Item:
    def __init__(self, value, weight):
        self.value = value  
        self.weight = weight  
        self.ratio = value / weight  

def fractional_knapsack(items, capacity):
    items.sort(key=lambda x: x.ratio, reverse=True)
    
    total_value = 0.0  
    for item in items:
        if capacity >= item.weight:  
            capacity -= item.weight  
            total_value += item.value  
        else:  
            total_value += item.value * (capacity / item.weight)  
            break  

    return total_value  

if __name__ == "__main__":
    n = int(input("Элементийн тоог оруулна уу: "))  
    items = []  
    for i in range(n):
        while True:
            try:
                value, weight = map(int, input(f"Элемент {i + 1}-ийн үнэ ба жинг оруулна уу (хооронд нь зайгаар тусгаарласан): ").split())
                items.append(Item(value, weight)) 
                break  
            except ValueError:
                print("Буруу оруулга. Тайлбар: хоёр бүтэн тоог зайгаар тусгаарлан оруулна уу.")
    
    capacity = int(input("Зоорийн багтаамжийг оруулна уу: "))  
    max_value = fractional_knapsack(items, capacity)  
    print(f"Зоорины хамгийн их утга = {max_value:.2f}")  
