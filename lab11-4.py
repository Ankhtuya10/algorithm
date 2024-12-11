from collections import defaultdict

class Solution:
    def findOrder(self, numCourses, prerequisites):
        # Хөршийн жагсаалт үүсгэх
        adj_list = defaultdict(list)
        for course, prereq in prerequisites:
            adj_list[prereq].append(course)

        # Төрөл бүрийн зангилааны төлөв: 0 = айлчлаагүй, 1 = айлчилж байна, 2 = дууссан
        state = [0] * numCourses
        topological_order = []
        is_possible = [True]  # Mutable list to replace nonlocal

        def dfs(node):
            if not is_possible[0]:  # Цикл илэрсэн бол шууд буцах
                return
            
            state[node] = 1  # Айлчилж байна
            for neighbor in adj_list[node]:
                if state[neighbor] == 0:  # Хөрш рүү нэвтрэх
                    dfs(neighbor)
                elif state[neighbor] == 1:  # Цикл илэрсэн
                    is_possible[0] = False

            state[node] = 2  # Дууссан
            topological_order.append(node)  # Reverse postorder

        # Бүх зангилааг шалгах
        for course in range(numCourses):
            if state[course] == 0:
                dfs(course)

        # Цикл илэрсэн бол хоосон массив буцаах
        if not is_possible[0]:
            return []

        # Reverse postorder-г буцаах
        return topological_order[::-1]

# Туршилтын жишээ:
if __name__ == "__main__":
    solution = Solution()
    print(solution.findOrder(2, [[1, 0]]))  # Гаралт: [0, 1]
    print(solution.findOrder(4, [[1, 0], [2, 0], [3, 1], [3, 2]]))  # Гаралт: [0, 1, 2, 3] эсвэл [0, 2, 1, 3]
    print(solution.findOrder(1, []))  # Гаралт: [0]