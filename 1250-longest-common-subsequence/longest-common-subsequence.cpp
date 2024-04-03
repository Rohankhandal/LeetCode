class Solution {
public:
    int solve(string t1,string t2,int i,int j)
    {
       if(i==t1.size()) return 0;
       if(j==t2.size()) return 0;
        int ans=0;
        if(t1[i]==t2[j])
        {
            ans+=1+solve(t1,t2,i+1,j+1);
        }
        else
        {
            ans+=0+max(solve(t1,t2,i,j+1),solve(t1,t2,i+1,j));
        }
        return ans;
    }
    int solveTop(string &t1,string &t2,int i,int j ,vector<vector<int>>&dp)
    {
       if(i==t1.size()) return 0;
       if(j==t2.size()) return 0;
       if(dp[i][j]!=-1) return dp[i][j];

        int ans=0;
        if(t1[i]==t2[j])
        {
            ans+=1+solveTop(t1,t2,i+1,j+1,dp);
        }
        else
        {
            ans+=0+max(solveTop(t1,t2,i,j+1,dp),solveTop(t1,t2,i+1,j,dp));
        }
        dp[i][j]=ans;
        return dp[i][j];
    }
    int longestCommonSubsequence(string a, string b) {
        // return solve(a,b,0,0);

        vector<vector<int>>dp(a.length(),vector<int>(b.length(),-1));
        return solveTop(a,b,0,0,dp);
    }
};