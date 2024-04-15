class Solution {
public:
    int solve(int n)
    {
        if(n==0) return 1;
        if(n<0) return 0;

        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            ans=min(ans,1+solve(n-i*i));
        }
        return ans;
    }
    int solve(int n,vector<int>&dp)
    {
        if(n==0) return 1;
        if(n<0) return 0;
        if(dp[n]!=-1) return dp[n];
        int ans=INT_MAX;
        for(int i=1;i*i<=n;i++)
        {
            ans=min(ans,1+solve(n-i*i,dp));
        }
        return dp[n]=ans;
    }
    int solveTab(int n)
    {
        vector<int>dp(n+1,0);
        dp[0]=1;
        
      
        for(int i=1;i<=n;i++)
        {
              int ans=INT_MAX;
            for(int j=1;j*j<=i;j++)
            {
                ans=min(ans,1+dp[i-j*j]);
            }
            dp[i]=ans;
        }
        return dp[n];
    }
    int numSquares(int n) {
        // return solve(n)-1;

        // vector<int>dp(n+1,-1);
        // return solve(n,dp)-1;

        return solveTab(n)-1;
    }
};