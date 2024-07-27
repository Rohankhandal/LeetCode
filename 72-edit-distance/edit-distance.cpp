class Solution {
public:
    int solve(string &word1,string &word2,int i,int j)
    {
        if(i>=word1.size()) return word2.size()-j;
        if(j>=word2.size()) return word1.size()-i;
        int ans=INT_MAX;
        int op1=INT_MAX;
        if(word1[i]==word2[j])
        {
            op1=solve(word1,word2,i+1,j+1);
        }
        else
        {
            int insert=1+solve(word1,word2,i,j+1);
            int replace=1+solve(word1,word2,i+1,j+1);
            int del=1+solve(word1,word2,i+1,j);
            ans=min({insert,replace,del});

        }
        return min(ans,op1);
    }

    // 2.Memoziation
     int solveMem(string &word1, string &word2, int i, int j, vector<vector<int>>& dp) {
        if (i >= word1.size()) return word2.size() - j;
        if (j >= word2.size()) return word1.size() - i;

        if (dp[i][j] != -1) return dp[i][j];

        if (word1[i] == word2[j]) {
            dp[i][j] = solveMem(word1, word2, i + 1, j + 1, dp);
        } else {
            int insert = 1 + solveMem(word1, word2, i, j + 1, dp);
            int replace = 1 + solveMem(word1, word2, i + 1, j + 1, dp);
            int del = 1 + solveMem(word1, word2, i + 1, j, dp);
            dp[i][j] = min({insert, replace, del});
        }

        return dp[i][j];
    }

    // 3.Tabluation
    int solveTab(string &word1, string &word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));

        // Fill the base cases
        for (int j = 0; j <= m; ++j) {
            dp[n][j] = m - j;  // If word1 is empty, we need to insert all remaining characters of word2
        }
        for (int i = 0; i <= n; ++i) {
            dp[i][m] = n - i;  // If word2 is empty, we need to delete all remaining characters of word1
        }

        // Fill the DP table
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (word1[i] == word2[j]) {
                    dp[i][j] = dp[i + 1][j + 1];  // No operation needed if characters match
                } else {
                    int insert = 1 + dp[i][j + 1];   // Insert word2[j] into word1
                    int replace = 1 + dp[i + 1][j + 1];  // Replace word1[i] with word2[j]
                    int del = 1 + dp[i + 1][j];      // Delete word1[i]
                    dp[i][j] = std::min({insert, replace, del});
                }
            }
        }

        // The answer is in dp[0][0], which is the min number of operations to convert word1 to word2
        return dp[0][0];
    }


    // 4.Space
    // 3.Tabluation
    int space(string &word1, string &word2) {
        int n = word1.size();
        int m = word2.size();
        // vector<vector<int>> dp(n + 1, vector<int>(m + 1, 0));
        vector<int>curr(m+1,0);
        vector<int>next(m+1,0);

        // Fill the base cases
        for (int j = 0; j <= m; ++j) {
           next[j] = m - j;  
        }

        // Fill the DP table
        for (int i = n - 1; i >= 0; --i) {
             //(IMP) from the base case
             curr[m]=n-i;

            for (int j = m - 1; j >= 0; --j) {

                if (word1[i] == word2[j]) {
                    curr[j] = next[j + 1];  // No operation needed if characters match
                } else {
                    int insert = 1 + curr[j + 1];   // Insert word2[j] into word1
                    int replace = 1 + next[j + 1];  // Replace word1[i] with word2[j]
                    int del = 1 + next[j];      // Delete word1[i]
                    curr[j] = min({insert, replace, del});
                }
            }
            next=curr;
        }

        return next[0];
    }
    int minDistance(string word1, string word2) {
        // return solve(word1,word2,0,0);


        // 2.Memoziation
        // vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        // return solveMem(word1, word2, 0, 0, dp);


        // 3.Tabluation
        // return solveTab(word1,word2);

        // 4.Space
        return space(word1,word2);
    }
};