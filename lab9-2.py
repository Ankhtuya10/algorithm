from collections import deque

class MyStack:
    def __init__(self):
        # Ээлж дарааллууд
        self.q1 = deque()
        self.q2 = deque()

    def push(self, x):
        # Шинэ элементийг `q2` дээр нэмэх
        self.q2.append(x)
        # `q1` дээрх бүх элементүүдийг `q2` руу шилжүүлнэ
        while self.q1:
            self.q2.append(self.q1.popleft())
        # `q1` болон `q2`-г солих
        self.q1, self.q2 = self.q2, self.q1

    def pop(self):
        # `q1`-ээс хамгийн эхний элемент гаргах
        return self.q1.popleft()

    def top(self):
        # `q1`-ийн хамгийн эхний элементийг буцаах
        return self.q1[0]

    def empty(self):
        # `q1` хоосон эсэхийг шалгах
        return not self.q1