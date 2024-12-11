class MyQueue:
    def __init__(self):
        # Хоёр стек ашиглана: оруулах (stack_in) болон гаргах (stack_out)
        self.stack_in = []  # Оруулах стек
        self.stack_out = []  # Гаргах стек

    def push(self, x):
        # x элементийг оруулах стект нэмнэ
        self.stack_in.append(x)

    def pop(self):
        # Эхний элементийг гаргах стект шилжүүлж, гаргана
        self._transfer_in_to_out()
        return self.stack_out.pop()  # Гаргах стекийн хамгийн дээд элементийг гаргана

    def peek(self):
        # Эхний элементийг буцаах боловч гаргахгүй
        self._transfer_in_to_out()
        return self.stack_out[-1]  # Гаргах стекийн хамгийн дээд элементийг буцаана

    def empty(self):
        # Одоо хоосон эсэхийг шалгана
        return not self.stack_in and not self.stack_out

    def _transfer_in_to_out(self):
        # Хэрвээ гаргах стек хоосон байвал, оруулах стекийн бүх элементийг шилжүүлнэ
        if not self.stack_out:
            while self.stack_in:
                self.stack_out.append(self.stack_in.pop())  # Оруулах стекийн элементүүдийг гаргах стект хийнэ
