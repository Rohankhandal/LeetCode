class Solution {
public:
    int solve(string word1, string word2,int i,int j){
        int n=word1.size();
        int m=word2.size();
        if(i>=n && j>=m) return 0;
        if(i>=n) return m-j;
        if(j>=m) return n-i;
        int ans=INT_MAX;
        if(word1[i]==word2[j])
        {
            ans=solve(word1,word2,i+1,j+1);
        }
        else
        {
            ans=1+min(solve(word1,word2,i+1,j),solve(word1,word2,i,j+1));
        }
        return ans;
    }

    int solveMem(string word1, string word2,int i,int j,vector<vector<int>>&dp){
        int n=word1.size();
        int m=word2.size();
        if(i>=n && j>=m) return 0;
        if(i>=n) return m-j;
        if(j>=m) return n-i;

        if(dp[i][j]!=-1) return dp[i][j];
        int ans=INT_MAX;
        if(word1[i]==word2[j])
        {
            ans=solveMem(word1,word2,i+1,j+1,dp);
        }
        else
        {
            ans=1+min(solveMem(word1,word2,i+1,j,dp),solveMem(word1,word2,i,j+1,dp));
        }
        return  dp[i][j]=ans;
    }

    int minDistance(string word1, string word2) {
        int n=word1.size();
        int m=word2.size();

        // return solve(word1,word2,0,0);

        //2.Memoziation
        vector<vector<int>>dp(n,vector<int>(m,-1));
        return solveMem(word1,word2,0,0,dp);
    }
};