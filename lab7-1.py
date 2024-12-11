class Item:
    def __init__(self, value, weight):
        self.value = value  # Элементын үнэ
        self.weight = weight  # Элементын жин
        self.ratio = value / weight  # Үнэтэй жингийн харьцаа (value-to-weight ratio)

def fractional_knapsack(items, capacity):
    # Элементуудыг үнэ/жингийн харьцаагаар буурахаар нь эрэмбэлнэ
    items.sort(key=lambda x: x.ratio, reverse=True)
    
    total_value = 0.0  # Нийт утга
    for item in items:
        if capacity >= item.weight:  # Хэрэв багтаах хүчин чадал хангалттай бол
            capacity -= item.weight  # Жингийн утгыг багтаах хүчин чадалд хасна
            total_value += item.value  # Элементийн үнийг нэмнэ
        else:  # Хэрэв элемент бүхэлдээ багтахгүй бол
            total_value += item.value * (capacity / item.weight)  # Багтах хэсгийн үнийг нэмнэ
            break  # Бусад элементийг орхино

    return total_value  # Нийт утга

# Жишээ ашиглалт
if __name__ == "__main__":
    n = int(input("Элементийн тоог оруулна уу: "))  # Элементийн тоог авна
    items = []  # Элементийг хадгалах жагсаалт
    for i in range(n):
        while True:
            try:
                value, weight = map(int, input(f"Элемент {i + 1}-ийн үнэ ба жинг оруулна уу (хооронд нь зайгаар тусгаарласан): ").split())
                items.append(Item(value, weight))  # Элементийг жагсаалтанд нэмнэ
                break  # Зөв форматтай бол гадагшлах
            except ValueError:
                print("Буруу оруулга. Тайлбар: хоёр бүтэн тоог зайгаар тусгаарлан оруулна уу.")
    
    capacity = int(input("Зоорийн багтаамжийг оруулна уу: "))  # Зоорийн багтаамжийг оруулна
    max_value = fractional_knapsack(items, capacity)  # Хамгийн их утга
    print(f"Зоорины хамгийн их утга = {max_value:.2f}")  # Хамгийн их утга гаргана
