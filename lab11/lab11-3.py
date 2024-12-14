from collections import deque

class Solution:
    def openLock(self, deadends, target):
        dead_set = set(deadends)
        
        if "0000" in dead_set:
            return -1
        
        queue = deque([("0000", 0)])  
        visited = set("0000")  

        def get_neighbors(state):
            neighbors = []
            for i in range(4):  
                digit = int(state[i])
                for move in (-1, 1):  
                    new_digit = (digit + move) % 10
                    neighbors.append(state[:i] + str(new_digit) + state[i + 1:])
            return neighbors

        while queue:
            current, moves = queue.popleft()
            if current == target:
                return moves
            for neighbor in get_neighbors(current):
                if neighbor not in visited and neighbor not in dead_set:
                    queue.append((neighbor, moves + 1))
                    visited.add(neighbor)
        return -1
solution = Solution()
print(solution.openLock(["0201", "0101", "0102", "1212", "2002"], "0202"))  
print(solution.openLock(["8888"], "0009"))  
print(solution.openLock(["8887", "8889", "8878", "8898", "8788", "8988", "7888", "9888"], "8888"))  