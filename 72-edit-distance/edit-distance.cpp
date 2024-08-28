class Solution {
public:
    int solve(string word1, string word2, int i, int j) {
        int n = word1.size();
        int m = word2.size();

        // Base case: if we've exhausted all characters in word1
        if (i >= n) {
            return m - j; // Remaining characters in word2 need to be inserted
        }

        // Base case: if we've exhausted all characters in word2
        if (j >= m) {
            return n - i; // Remaining characters in word1 need to be deleted
        }

        int ans = INT_MAX;

        // If characters match, move to the next characters in both strings
        if (word1[i] == word2[j]) {
            ans = solve(word1, word2, i + 1, j + 1);
        } else {
            // Calculate the costs of insert, remove, and replace operations
            int insert = solve(word1, word2, i, j + 1);  // Insert character in word1
            int remove = solve(word1, word2, i + 1, j);  // Remove character from word1
            int replace = solve(word1, word2, i + 1, j + 1);  // Replace character in word1

            // Choose the operation with the minimum cost
            ans = 1 + min({insert, remove, replace});
        }

        return ans;
    }


     int solveMem(string word1, string word2, int i, int j,vector<vector<int>>&dp) {
        int n = word1.size();
        int m = word2.size();

        // Base case: if we've exhausted all characters in word1
        if (i >= n) {
            return m - j; // Remaining characters in word2 need to be inserted
        }

        // Base case: if we've exhausted all characters in word2
        if (j >= m) {
            return n - i; // Remaining characters in word1 need to be deleted
        }

        if(dp[i][j]!=-1) return dp[i][j];

        int ans = INT_MAX;

        // If characters match, move to the next characters in both strings
        if (word1[i] == word2[j]) {
            ans = solveMem(word1, word2, i + 1, j + 1,dp);
        } else {
            // Calculate the costs of insert, remove, and replace operations
            int insert = solveMem(word1, word2, i, j + 1,dp);  // Insert character in word1
            int remove = solveMem(word1, word2, i + 1, j,dp);  // Remove character from word1
            int replace = solveMem(word1, word2, i + 1, j + 1,dp);  // Replace character in word1

            // Choose the operation with the minimum cost
            ans = 1 + min({insert, remove, replace});
        }

        return dp[i][j]=ans;
    }

    //3.Tabluation
    int solveTab(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();

        vector<vector<int>>dp(n+1,vector<int>(m+1,0));

        for(int j=0;j<=m;j++)
        {
            dp[n][j]=m-j;
        }

        for(int i=0;i<=n;i++)
        {
            dp[i][m]=n-i;
        }


        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--){
                int ans = INT_MAX;

                // If characters match, move to the next characters in both strings
                if (word1[i] == word2[j]) {
                    ans = dp[i + 1][ j + 1];
                } else {
                    // Calculate the costs of insert, remove, and replace operations
                    int insert = dp[i][ j + 1];  // Insert character in word1
                    int remove = dp[i + 1][ j ]; // Remove character from word1
                    int replace = dp[i + 1][ j + 1];  // Replace character in word1

                    // Choose the operation with the minimum cost
                    ans = 1 + min({insert, remove, replace});
                }

                dp[i][j]=ans;
            }
        }
        return dp[0][0];
        
    }


    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();
        // return solve(word1, word2, 0, 0);


        //2.Memoziation
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solveMem(word1,word2,0,0,dp);

        //3.Tabluation
        return solveTab(word1,word2);
    }
};
