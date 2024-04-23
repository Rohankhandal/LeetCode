class Solution {
public:
    int solve(int start,int end)
    {
        if(start>=end)
        {
            return 0; //we choose the right number and win
        }
        int ans=INT_MAX;
        for(int i=start;i<=end;i++)
        {
            ans=min(ans,i+max(solve(1,i-1),solve(i+1,end)));
        }
        return ans;

    }
    int solveMem(int start,int end,vector<vector<int>>&dp)
    {
        if(start>=end)
        {
            return 0; //we choose the right number and win
        }
        if(dp[start][end]!=-1) return dp[start][end];
        int ans=INT_MAX;
        for(int i=start;i<=end;i++)
        {
            ans=min(ans,i+max(solveMem(start,i-1,dp),solveMem(i+1,end,dp)));
        }
        return dp[start][end]=ans;

    }
    int getMoneyAmount(int n) {
    //    return  solve(1,n);

    //2.Memoization
        vector<vector<int>>dp(n+1,vector<int>(n+1,-1));
        return solveMem(1,n,dp);
    }
};