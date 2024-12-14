class Solution:
    def checkValidString(self, s):
        stack = [(0, 0)]  
        while stack:
            index, balance = stack.pop()
            if balance < 0:
                continue
            if index == len(s) and balance == 0:
                return True
            if index < len(s):
                if s[index] == '(':
                    stack.append((index + 1, balance + 1))  
                elif s[index] == ')':
                    stack.append((index + 1, balance - 1))  
                else:  # '*'
                    stack.append((index + 1, balance + 1))  
                    stack.append((index + 1, balance - 1))  
                    stack.append((index + 1, balance))      
        return False
solution = Solution()
print(solution.checkValidString("()"))    
print(solution.checkValidString("(*)"))   
print(solution.checkValidString("(*))")) 