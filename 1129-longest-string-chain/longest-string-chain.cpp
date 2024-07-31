class Solution {
public:
    // Helper function to determine if words[i] can be a valid extension of
    // words[prev]
    bool isSafe( const string &s1, const string &s2) {
        if (s1.size() != s2.size() + 1)
            return false;

        int first = 0;
        int second = 0;

        while (first < s1.size()) {
            if (second < s2.size() && s1[first] == s2[second]) {
                first++;
                second++;
            } else
                first++;
        }
        if (first == s1.size() && second == s2.size())
            return true;
        else
            return false;
    }

    // Recursive function to find the longest chain ending at word i
    int solve(vector<string>& words, int i, int prev) {
        int n = words.size();
        if (i >= n)
            return 0;

        int take = 0;
        if (prev == -1 || isSafe(words[i],words[prev])) {
            take = 1 + solve(words, i + 1, i);
        }

        int noTake = solve(words, i + 1, prev);

        return max(take, noTake);
    }


    // 2.Memoziation
    // Recursive function to find the longest chain ending at word i
    int solveMem(vector<string>& words, int i, int prev, vector<vector<int>>&dp) {
        int n = words.size();
        if (i >= n)
            return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int take = 0;
        if (prev == -1 || isSafe(words[i],words[prev])) {
            take = 1 + solveMem(words, i + 1, i,dp);
        }

        int noTake = solveMem(words, i + 1, prev,dp);

        return dp[i][prev+1]=max(take, noTake);
    }


    // 3.Tabluation
    // Recursive function to find the longest chain ending at word i
    int solveTab(vector<string>& words) {
        int n = words.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                int take = 0;
                if (prev == -1 || isSafe(words[i],words[prev])) {
                    take = 1 + dp[i + 1][i+1];
                }

                int noTake = dp[i + 1][ prev+1];

                dp[i][prev+1]=max(take, noTake);
            }
        }
        return dp[0][0];
        
    }
     static bool myFunction(string& s1, string& s2) {
        return s1.length() < s2.length();
    }
    // Main function to sort the words and initiate the recursive solution
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        sort(words.begin(), words.end(),myFunction);
        
        // return solve(words, 0, -1);

        // vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        // return solveMem(words,0,-1,dp);


        return solveTab(words);

    }
};