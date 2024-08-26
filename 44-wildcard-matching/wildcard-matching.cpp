class Solution {
public:
    // Recursive solution with pattern matching
    bool solve(int i, int j, string str, string pattern) {
        // Base case: both strings are fully matched
        if(i < 0 && j < 0) return true;
        // If str is not fully matched but pattern is, return false
        if(i >= 0 && j < 0) return false;
        // If str is fully matched but pattern is not, check if remaining pattern is all '*'
        if(i < 0 && j >= 0) {
            for(int m = 0; m <= j; m++) {
                if(pattern[m] != '*') return false;
            }
            return true;
        }

        // Match current characters or wildcard '?'
        if(str[i] == pattern[j] || pattern[j] == '?') {
            return solve(i-1, j-1, str, pattern);
        }
        // Handle '*' wildcard, which can match zero or more characters
        if(pattern[j] == '*') {
            return solve(i-1, j, str, pattern) || solve(i, j-1, str, pattern);
        }
         
        return false; // No match found
    }

    // Recursive solution with memoization
    bool solveMem(int i, int j, string &str, string &pattern, vector<vector<int>>& dp) {
        if(i < 0 && j < 0) return true;
        if(i >= 0 && j < 0) return false;
        if(i < 0 && j >= 0) {
            for(int m = 0; m <= j; m++) {
                if(pattern[m] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j]; // Check memoized result

        if(str[i] == pattern[j] || pattern[j] == '?') {
            return dp[i][j] = solveMem(i-1, j-1, str, pattern, dp);
        }
        if(pattern[j] == '*') {
            return dp[i][j] = (solveMem(i-1, j, str, pattern, dp) || solveMem(i, j-1, str, pattern, dp));
        }
         
        return dp[i][j] = false;
    }

    // 1-based indexing for memoization (preparation for tabulation)
    bool solveMem1Index(int i, int j, string &str, string &pattern, vector<vector<int>>& dp) {
        if(i == 0 && j == 0) return true;
        if(i > 0 && j == 0) return false;
        if(i == 0 && j > 0) {
            for(int m = 1; m <= j; m++) {
                if(pattern[m-1] != '*') return false;
            }
            return true;
        }

        if(dp[i][j] != -1) return dp[i][j]; // Check memoized result

        if(str[i-1] == pattern[j-1] || pattern[j-1] == '?') {
            return dp[i][j] = solveMem1Index(i-1, j-1, str, pattern, dp);
        }
        if(pattern[j-1] == '*') {
            return dp[i][j] = (solveMem1Index(i-1, j, str, pattern, dp) || solveMem1Index(i, j-1, str, pattern, dp));
        }
         
        return dp[i][j] = false;
    }

    // Tabulation (bottom-up dynamic programming)
    bool solveTab(string &str, string &pattern) {
        int n1 = str.size();
        int n2 = pattern.size();
        vector<vector<bool>> dp(n1+1, vector<bool>(n2+1, false));

        dp[0][0] = true; // Empty string matches empty pattern

        // Handle patterns that can only consist of '*' at the beginning
        for(int j = 1; j <= n2; j++) {
            bool flag = true;
            for(int m = 1; m <= j; m++) {
                if(pattern[m-1] != '*') {
                    flag = false;
                    break;
                } 
            }
            dp[0][j] = flag;
        }

        // Fill the dp table
        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if(str[i-1] == pattern[j-1] || pattern[j-1] == '?') {
                    dp[i][j] = dp[i-1][j-1]; // Match character or '?'
                } else if(pattern[j-1] == '*') {
                    dp[i][j] = (dp[i-1][j] || dp[i][j-1]); // '*' can match zero or more characters
                } else {
                    dp[i][j] = false; // No match found
                }
            }
        }

        return dp[n1][n2]; // Final result is in dp[n1][n2]
    }

    // Space optimization using two rows
    bool space(string &str, string &pattern) {
        int n1 = str.size();
        int n2 = pattern.size();
        vector<bool> curr(n2+1, false);
        vector<bool> prev(n2+1, false);

        prev[0] = true; // Empty string matches empty pattern

        // Handle patterns that can only consist of '*' at the beginning
        for(int j = 1; j <= n2; j++) {
            bool flag = true;
            for(int m = 1; m <= j; m++) {
                if(pattern[m-1] != '*') {
                    flag = false;
                    break;
                } 
            }
            prev[j] = flag;
        }

        // Fill the dp rows
        for(int i = 1; i <= n1; i++) {
            for(int j = 1; j <= n2; j++) {
                if(str[i-1] == pattern[j-1] || pattern[j-1] == '?') {
                    curr[j] = prev[j-1]; // Match character or '?'
                } else if(pattern[j-1] == '*') {
                    curr[j] = (prev[j] || curr[j-1]); // '*' can match zero or more characters
                } else {
                    curr[j] = false; // No match found
                }
            }
            prev = curr; // Move to the next row
        }

        return prev[n2]; // Final result is in prev[n2]
    }

    // Main function to check if the pattern matches the string
    bool isMatch(string str, string pattern) {
        int n1 = str.size();
        int n2 = pattern.size();

        // 1. Recursion (uncomment to use)
        // return solve(n1-1, n2-1, str, pattern);

        // 2. Memoization (uncomment to use)
        // vector<vector<int>> dp(n1, vector<int>(n2, -1));
        // return solveMem(n1-1, n2-1, str, pattern, dp);

        // 3. 1-indexed Memoization (uncomment to use)
        // vector<vector<int>> dp(n1+1, vector<int>(n2+1, -1));
        // return solveMem1Index(n1, n2, str, pattern, dp);

        // 4. Tabulation (uncomment to use)
        // return solveTab(str, pattern);

        // 5. Space optimization
        return space(str, pattern); // Default to space optimization
    }
};
