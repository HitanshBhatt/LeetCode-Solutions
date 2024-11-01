class Solution {
public:
    string longestPalindrome(string s) {
        if (s.empty()) return "";
        
        int start = 0, maxLength = 1;
        
        for (int i = 0; i < s.length(); i++) {
            // Check for odd-length palindromes
            int len1 = expandAroundCenter(s, i, i);
            // Check for even-length palindromes
            int len2 = expandAroundCenter(s, i, i + 1);
            // Get the maximum length found
            int len = max(len1, len2);
            if (len > maxLength) {
                maxLength = len;
                start = i - (maxLength - 1) / 2; // Calculate the starting index
            }
        }
        
        return s.substr(start, maxLength);
    }

private:
    int expandAroundCenter(const string& s, int left, int right) {
        while (left >= 0 && right < s.length() && s[left] == s[right]) {
            left--;
            right++;
        }
        // Return the length of the palindrome found
        return right - left - 1; // (right - 1) - (left + 1) + 1 = right - left - 1
    }
};
