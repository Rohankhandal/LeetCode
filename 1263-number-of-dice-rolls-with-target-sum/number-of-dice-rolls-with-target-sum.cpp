int M=1e9+7;
class Solution {
public:
    int solve(int n,int face,int tar)
    {
        if(tar<0) return 0;
        if(n==0 and tar==0) return 1;
        if(n!=0 and tar==0) return 0;
        if(n==0 and tar!=0) return 0;

        int ans=0;
        for(int i=1;i<=face;i++)
        {
            ans+=solve(n-1,face,tar-i);
        }
        return ans;
    }
    //2.Memoization
    int solveMem(int n,int face,int tar,vector<vector<int>>&dp)
    {
        if(tar<0) return 0;
        if(n==0 and tar==0) return 1;
        if(n!=0 and tar==0) return 0;
        if(n==0 and tar!=0) return 0;

        if(dp[n][tar]!=-1) return dp[n][tar];

        int ans=0;
        for(int i=1;i<=face;i++)
        {
            ans=(ans%M+solveMem(n-1,face,tar-i,dp)%M)%M;
        }
        return dp[n][tar]=ans%M;
    }


    //3.Memoization
    int solveTab(int n,int f,int t)
    {
        vector<vector<int>>dp(n+1,vector<int>(t+1,0));
        dp[0][0]=1;

        int ans=0;
        for(int i=1;i<=n;i++)   //dice
        {
            for(int tar=1;tar<=t;tar++)  //target
            {
                int ans=0;
                for(int face=1;face<=f;face++)   //face
                {
                    
                    if(tar-face>=0)
                        ans=(ans%M+dp[i-1][tar-face]%M)%M;
                }
                dp[i][tar]=ans%M;
            }
        }
        
        return dp[n][t];
    }
    int numRollsToTarget(int n, int k, int target) {
        // return solve(n,k,target);

        //2.Memoization
        // vector<vector<int>>dp(n+1,vector<int>(target+1,-1));
        // return solveMem(n,k,target,dp);

        //3.Tabluation
        return solveTab(n,k,target);
    }
};