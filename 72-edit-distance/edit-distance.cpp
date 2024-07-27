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
    int minDistance(string word1, string word2) {
        // return solve(word1,word2,0,0);


        // 2.Memoziation
        vector<vector<int>> dp(word1.size(), vector<int>(word2.size(), -1));
        return solveMem(word1, word2, 0, 0, dp);
    }
};