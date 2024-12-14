import unittest

def dfs(node, visited, stack, graph):
    visited.add(node)
    
    for neighbour in graph[node]:
        if neighbour not in visited:
            dfs(neighbour, visited, stack, graph)
    
    stack.append(node)

def topological_sort(graph):
    visited = set()
    stack = []

    for vertex in graph:
        if vertex not in visited:
            dfs(vertex, visited, stack, graph)

    return stack[::-1]

class TestTopologicalSort(unittest.TestCase):
    
    def test_topological_sort(self):
        graph = {
            0: [],
            1: [],
            2: [3],
            3: [1],
            4: [0, 1],
            5: [0, 2]
        }
        
    
        result = topological_sort(graph)
        
        expected = [4, 5, 2, 0, 3, 1]  
        self.assertEqual(result, expected)

if __name__ == '__main__':
    unittest.main()