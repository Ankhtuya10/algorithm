from collections import defaultdict

class Solution:
    def findOrder(self, numCourses, prerequisites):
        adj_list = defaultdict(list)
        for course, prereq in prerequisites:
            adj_list[prereq].append(course)
        state = [0] * numCourses
        topological_order = []
        is_possible = [True]  

        def dfs(node):
            if not is_possible[0]:  
                return
            
            state[node] = 1  
            for neighbor in adj_list[node]:
                if state[neighbor] == 0:  
                    dfs(neighbor)
                elif state[neighbor] == 1: 
                    is_possible[0] = False

            state[node] = 2  
            topological_order.append(node)  

        for course in range(numCourses):
            if state[course] == 0:
                dfs(course)
        if not is_possible[0]:
            return []

        return topological_order[::-1]
if __name__ == "__main__":
    solution = Solution()
    print(solution.findOrder(2, [[1, 0]]))  
    print(solution.findOrder(4, [[1, 0], [2, 0], [3, 1], [3, 2]]))  
    print(solution.findOrder(1, []))  