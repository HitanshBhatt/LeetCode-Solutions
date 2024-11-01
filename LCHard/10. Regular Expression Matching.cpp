class Solution {
public:
    bool isMatch(string s, string p) {
        /*
            Dynamic Programming approach:
                - Create a 2D DP table where dp[i][j] is true if the first i characters of the string
                  s match the first j characters of the pattern p
        */

        //dp table fo size (m x n) where m: length of s
        //n: length of p
        int m = s.size();
        int n = p.size();

        vector<vector<bool>> dp(m+1, vector<bool>(n+1, false));

        //initialize dp table
        dp[0][0] = true;

        //Handle patterns like a*, a*b*, etc. that can match an empty string
        for (int j = 1; j <= n; ++j){
            if (p[j-1] == '*'){
                dp[0][j] = dp[0][j-2];
            }
        }

        //fill the dp table
        for (int i = 1; i <= m; i++) {
            for (int j = 1; j <= n; j++) {
                // Check if characters match or if the pattern has a '.'
                if (p[j - 1] == s[i - 1] || p[j - 1] == '.') {
                    dp[i][j] = dp[i - 1][j - 1];
                }
                // Check if the pattern has '*'
                else if (p[j - 1] == '*') {
                    // Match zero of the preceding element
                    dp[i][j] = dp[i][j - 2];
                    // Match one or more of the preceding element
                    if (p[j - 2] == s[i - 1] || p[j - 2] == '.') {
                        dp[i][j] = dp[i][j] || dp[i - 1][j];
                    }
                }
            }
        }

        return dp[m][n];
    }
};
