#include <iostream>
#include <string>
#include <unordered_set>
#include <algorithm>
using namespace std;

class Solution {
public:
    string longestNiceSubstring(string s) {
        return longestNiceSubstringHelper(s, 0, s.size() - 1);
    }

private:
    bool isNice(const string& sub) {
        unordered_set<char> chars(sub.begin(), sub.end());
        for (char c : chars) {
            if (islower(c) && chars.find(toupper(c)) == chars.end()) {
                return false;
            }
            if (isupper(c) && chars.find(tolower(c)) == chars.end()) {
                return false;
            }
        }
        return true;
    }

    string longestNiceSubstringHelper(const string& s, int left, int right) {
        if (left >= right) {
            return "";
        }

        unordered_set<char> chars(s.begin() + left, s.begin() + right + 1);
        for (int i = left; i <= right; ++i) {
            if (!(chars.count(tolower(s[i])) && chars.count(toupper(s[i])))) {
                string leftPart = longestNiceSubstringHelper(s, left, i - 1);
                string rightPart = longestNiceSubstringHelper(s, i + 1, right);
                return leftPart.size() >= rightPart.size() ? leftPart : rightPart;
            }
        }

        return s.substr(left, right - left + 1);
    }
};

int main() {
    Solution sol;
    string s1 = "YazaAay";
    string s2 = "Bb";
    string s3 = "c";

    cout << sol.longestNiceSubstring(s1) << endl;  
    cout << sol.longestNiceSubstring(s2) << endl;  
    cout << sol.longestNiceSubstring(s3) << endl;  

    return 0;
}