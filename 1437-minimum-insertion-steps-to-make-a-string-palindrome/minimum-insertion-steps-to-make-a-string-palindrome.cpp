class Solution {
public:
    int solve(string s,int l,int r)
    {
        if(l>r) return 0;

        int take=0;
        int skip1=0,skip2=0;
        if(s[l]==s[r])
        {
            return solve(s,l+1,r-1);
        }
        else
        {
            skip1=1+solve(s,l+1,r);
            skip2=1+solve(s,l,r-1);
        }
        return min({skip1,skip2});
    }
    // 2.Memoziation
    int solveMem(string &s,int l,int r,vector<vector<int>>&dp)
    {
        if (l >= r) return 0; // Base case: if left index crosses right, no insertions are needed

        if (dp[l][r] != -1) return dp[l][r]; // Return memoized result if already computed

        if (s[l] == s[r]) {
            dp[l][r] = solveMem(s, l + 1, r - 1, dp); // No insertion needed if characters match
        } else {
            int insertLeft = 1 + solveMem(s, l + 1, r, dp); // Insert character matching s[r] at position l
            int insertRight = 1 + solveMem(s, l, r - 1, dp); // Insert character matching s[l] at position r
            dp[l][r] = min(insertLeft, insertRight); // Take the minimum of both options
        }

        return dp[l][r];
    }


    //3.Tabluation
    int solveTab(string &s)
    {
        int n=s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0)); 

        for(int l=n-1;l>=0;l--)
        {
            for(int r=0;r<n;r++)
            {
                if (l >= r) continue; 

                if (s[l] == s[r]) {
                    dp[l][r] = dp[l + 1][r - 1]; // No insertion needed if characters match
                } else {
                    int insertLeft = 1 + dp[l + 1][ r];
                    int insertRight = 1 + dp[l][r - 1]; 
                    dp[l][r] = min(insertLeft, insertRight);
                }
            }
        }
        return dp[0][n-1];

        
    }
    int minInsertions(string s) {
        // return solve(s,0,s.size()-1);

        // int n = s.size();
        // vector<vector<int>> dp(n, vector<int>(n, -1)); // Memoization table
        // return solveMem(s, 0, n - 1, dp);


        // 3.Tabluation
        return solveTab(s);
    }
};