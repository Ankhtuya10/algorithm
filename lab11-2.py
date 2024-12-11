class Solution:
    def checkValidString(self, s):
        # Стек ашиглан DFS хийх
        stack = [(0, 0)]  # (одоогийн индекс, тэнцвэр)

        while stack:
            index, balance = stack.pop()

            # Хэрэв тэнцвэр сөрөг бол боломжгүй тул дараагийн төлөвийг шалгах
            if balance < 0:
                continue

            # Хэрэв индекс мөрийн төгсгөлд хүрсэн бөгөөд тэнцвэр 0 байвал үнэн буцаана
            if index == len(s) and balance == 0:
                return True

            # Хэрэв мөрний төгсгөлд хүрээгүй бол дараагийн тэмдэгтүүдийг шалгах
            if index < len(s):
                if s[index] == '(':
                    stack.append((index + 1, balance + 1))  # '(' гэж үзэх
                elif s[index] == ')':
                    stack.append((index + 1, balance - 1))  # ')' гэж үзэх
                else:  # '*'
                    stack.append((index + 1, balance + 1))  # '(' гэж үзэх
                    stack.append((index + 1, balance - 1))  # ')' гэж үзэх
                    stack.append((index + 1, balance))      # '' гэж үзэх

        # Бүх боломжит төлөвийг шалгасны дараа хүчинтэй биш бол
        return False

# Жишээ ашиглалт
solution = Solution()
print(solution.checkValidString("()"))    # Гаралт: True
print(solution.checkValidString("(*)"))   # Гаралт: True
print(solution.checkValidString("(*))"))  # Гаралт: True
