class Fibonacci:
    def __init__(self):
        self.memo = {}

    def fib(self, n):
        if n == 0:
            return 0
        if n == 1:
            return 1
        if n in self.memo:
            return self.memo[n]  
        self.memo[n] = self.fib(n - 1) + self.fib(n - 2)  
        return self.memo[n]  
fib_calculator = Fibonacci()
n = 10 
result = fib_calculator.fib(n)
print(f"Fibonacci of {n} is {result}")
