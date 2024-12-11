def countPrimes(n):
    if n < 2:
        return 0

    # Анхны гэж үзсэн бүх тоонуудыг анхдагчаар үнэн гэж тодорхойлно
    is_prime = [True] * (n + 1)
    is_prime[0] = is_prime[1] = False  # 0 болон 1 нь анхны тоо биш

    # Эратосфений шүүлтүүрийг хэрэгжүүлнэ
    for i in range(2, int(n**0.5) + 1):
        if is_prime[i]:
            # i-ийн үржвэрүүдийг False (анхны биш) гэж тэмдэглэнэ
            for j in range(i * i, n + 1, i):
                is_prime[j] = False

    # Анхны тоонуудыг тоолж буцаана
    return sum(is_prime)

# Жишээ ашиглалт:
n = 18
print(countPrimes(n))  # Гаралт: 7 (Анхны тоонууд: 2, 3, 5, 7, 11, 13, 17)
