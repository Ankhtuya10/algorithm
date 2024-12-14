class Solution:
    def longestNiceSubstring(self, s):
        def is_nice(sub):
            chars = set(sub)
            for char in chars:
                if char.islower() and char.upper() not in chars:
                    return False
                if char.isupper() and char.lower() not in chars:
                    return False
            return True
        def longest_nice_substring(left, right):
            if left >= right:
                return ""

            chars = set(s[left:right + 1])
            for i in range(left, right + 1):
                if not (s[i].lower() in chars and s[i].upper() in chars):
                    left_part = longest_nice_substring(left, i - 1)
                    right_part = longest_nice_substring(i + 1, right)
                    return left_part if len(left_part) >= len(right_part) else right_part

            return s[left:right + 1]

        return longest_nice_substring(0, len(s) - 1)

if __name__ == "__main__":
    sol = Solution()
    s1 = "YazaAay"
    s2 = "Bb"
    s3 = "c"
    
    print(sol.longestNiceSubstring(s1))  
    print(sol.longestNiceSubstring(s2))  
    print(sol.longestNiceSubstring(s3))  