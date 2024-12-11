from collections import deque

class Solution:
    def openLock(self, deadends, target):
        # deadends-г хурдан хайлт хийхийн тулд set болгон хувиргах
        dead_set = set(deadends)
        
        # Хэрэв анхны төлөв deadend байвал -1-г шууд буцаах
        if "0000" in dead_set:
            return -1
        
        # BFS-ийн ээлжийг анхны төлөвөөр эхлүүлэх
        queue = deque([("0000", 0)])  # (одоогийн төлөв, хөдөлгөөний тоо)
        visited = set("0000")  # Зочилсон төлөвүүдийг хянахад ашиглах

        # Бүх боломжит дараагийн төлөвүүдийг үүсгэх функц
        def get_neighbors(state):
            neighbors = []
            for i in range(4):  # Дугуй тус бүрээр
                digit = int(state[i])
                for move in (-1, 1):  # Дугуйг урагш эсвэл хойш эргүүлэх
                    new_digit = (digit + move) % 10
                    neighbors.append(state[:i] + str(new_digit) + state[i + 1:])
            return neighbors

        # BFS-ийн гүйцэтгэл
        while queue:
            current, moves = queue.popleft()
            
            # Хэрэв зорилтот төлөвт хүрсэн бол хөдөлгөөний тоог буцаах
            if current == target:
                return moves
            
            # Хөрш төлөвүүдийг үүсгэж, тэдгээрийг боловсруулах
            for neighbor in get_neighbors(current):
                if neighbor not in visited and neighbor not in dead_set:
                    queue.append((neighbor, moves + 1))
                    visited.add(neighbor)

        # Хэрэв ээлж дуусч, зорилтот төлөвт хүрээгүй бол -1-г буцаах
        return -1

# Жишээ ашиглалт
solution = Solution()
print(solution.openLock(["0201", "0101", "0102", "1212", "2002"], "0202"))  # Гаралт: 6
print(solution.openLock(["8888"], "0009"))  # Гаралт: 1
print(solution.openLock(["8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"], "8888"))  # Гаралт: -1