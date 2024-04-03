class Solution {
public:
    int solve(int start,int end)
    {   if(start>=end) return 0;

        int ans=INT_MAX;
        
        for(int i=start;i<=end;i++)
        {
            ans=min(ans,i+ max(solve(start,i-1),solve(i+1,end)));
        }
        return ans;

    }
    int solveTop(int start,int end,vector<vector<int>>&dp)
    {   
        if(start>=end) return 0;
        if(dp[start][end]!=-1) return dp[start][end];

        int ans=INT_MAX;
        
        for(int i=start;i<=end;i++)
        {
            ans=min(ans,i+ max(solveTop(start,i-1,dp),solveTop(i+1,end,dp)));
        }
        dp[start][end]=ans;
        return dp[start][end];

    }
    int getMoneyAmount(int n) {
        // return solve(0,n);

        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveTop(0,n,dp);
    }
};