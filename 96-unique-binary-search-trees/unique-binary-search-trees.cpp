class Solution {
public:
    int solve(int n)
    {
        if(n==0 || n==1)
        {
            return 1;
        }   
        int ans=0;
        //think i as a root node
        for(int i=1;i<=n;i++)
        {
            ans+=solve(i-1)*solve(n-i);
        }
        return ans;
    }

    //2.Memoization
    int solveMem(int n,vector<int>&dp)
    {
        if(n==0 || n==1)
        {
            return 1;
        }   
        if(dp[n]!=-1) return dp[n];

        int ans=0;
        //think i as a root node
        for(int i=1;i<=n;i++)
        {
            ans+=solveMem(i-1,dp)*solveMem(n-i,dp);
        }
        return dp[n]=ans;
    }
    int numTrees(int n) {
        
        // return solve(n);


        //2.Memoization
        vector<int>dp(n+1,-1);
        return solveMem(n,dp);
    }
};