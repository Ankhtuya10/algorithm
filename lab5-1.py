class Fibonacci:
    def __init__(self):
        # Санах ой (memo) нь аль хэдийн тооцоолсон утгыг хадгална
        self.memo = {}

    def fib(self, n):
        # Үндсэн тохиолдлууд (0 болон 1-ийн хувьд утгууд шууд тодорхой)
        if n == 0:
            return 0
        if n == 1:
            return 1
        
        # Санах ойд байгаа эсэхийг шалгах
        if n in self.memo:
            return self.memo[n]  # Хэрэв хадгалагдсан бол шууд буцаана

        # Давталттай томъёо ашиглан утгыг тооцоолох
        self.memo[n] = self.fib(n - 1) + self.fib(n - 2)  # fib(n) = fib(n-1) + fib(n-2)
        return self.memo[n]  # Тооцоолсон утгыг буцаана

# Жишээ ашиглалт:
fib_calculator = Fibonacci()
n = 10  # n-ийн утгыг хүссэнээрээ өөрчилж болно
result = fib_calculator.fib(n)
print(f"Fibonacci of {n} is {result}")
