class Solution:
    def longestNiceSubstring(self, s):
        # Helper function to check if the substring is nice
        def is_nice(sub):
            chars = set(sub)
            for char in chars:
                if char.islower() and char.upper() not in chars:
                    return False
                if char.isupper() and char.lower() not in chars:
                    return False
            return True

        # Divide and conquer function using left and right pointers
        def longest_nice_substring(left, right):
            if left >= right:
                return ""

            # Check all characters in the current substring
            chars = set(s[left:right + 1])
            for i in range(left, right + 1):
                if not (s[i].lower() in chars and s[i].upper() in chars):
                    # Split the string at this invalid character
                    left_part = longest_nice_substring(left, i - 1)
                    right_part = longest_nice_substring(i + 1, right)
                    # Return the longest between the left and right part
                    return left_part if len(left_part) >= len(right_part) else right_part

            # If the whole substring is nice, return it
            return s[left:right + 1]

        return longest_nice_substring(0, len(s) - 1)

# Example usage
if __name__ == "__main__":
    sol = Solution()
    s1 = "YazaAay"
    s2 = "Bb"
    s3 = "c"
    
    print(sol.longestNiceSubstring(s1))  # Output: "aAa"
    print(sol.longestNiceSubstring(s2))  # Output: "Bb"
    print(sol.longestNiceSubstring(s3))  # Output: ""