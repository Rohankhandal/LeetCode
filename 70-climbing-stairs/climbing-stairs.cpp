class Solution {
public:
    int dp[46];

    int solve(int n)
    {
        if(n==0 || n==1) return 1;
        return solve(n-1)+solve(n-2);
    }
    //2.Memomization
    int solveMem(int n)
    {
        if(n==0 || n==1) return dp[n]=1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=solveMem(n-1)+solveMem(n-2);
    }
    //3.Tabluation
    int solveTab(int n)
    {
        vector<int>dp(n+1,0);
        dp[0]=1,dp[1]=1;

        for(int i=2;i<=n;i++)
        {
          dp[i]=dp[i-1]+dp[i-2];
        }
        return dp[n];
    }

    int climbStairs(int n) {
        // memset(dp,-1,sizeof(dp));
        // return solveMem(n);

        //3.Tabluation
        return solveTab(n);
    }
};