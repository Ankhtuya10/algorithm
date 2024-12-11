class Solution:
    def islandPerimeter(self, grid):
        rows, cols = len(grid), len(grid[0])
        visited = set()

        def dfs(r, c):
            # Хэрэв хязгаараас гарвал эсвэл ус байвал 1-ийг буцаах
            if r < 0 or r >= rows or c < 0 or c >= cols or grid[r][c] == 0:
                return 1
            # Хэрэв аль хэдийн зочилсон бол 0-ийг буцаах
            if (r, c) in visited:
                return 0
            
            visited.add((r, c))
            # Зэргэлдээ тал бүрийг шалгах
            perimeter = 0
            for dr, dc in [(-1, 0), (1, 0), (0, -1), (0, 1)]:
                perimeter += dfs(r + dr, c + dc)
            return perimeter

        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == 1:
                    # Эхний арлын нүд олмогц DFS эхлүүлнэ
                    return dfs(r, c)
