class Solution {
public:
    long long int MOD=1000000007;
    int solveUsingRec(int n,int k,int target)
    {
        if(target < 0 ) return 0;
        if(n==0 && target==0) return 1;
        if(n ==0 && target!=0) return 0;
        if(n!=0 && target==0)  return 0;

        int ans=0;
        for(int i=1; i<=k; i++)
        {
            ans=ans+solveUsingRec(n-1,k,target-i);

        }
        return ans;
    }
    int solveUsingTop(int n,int k,int target,vector<vector<long long int>>&dp)
    {
        if(target < 0 ) return 0;
        if(n==0 && target==0) return 1;
        if(n ==0 && target!=0) return 0;
        if(n!=0 && target==0)  return 0;

        if(dp[n][target]!=-1)
            return dp[n][target];

        int ans=0;
        for(int i=1; i<=k; i++)
        {
            ans=ans%MOD+solveUsingTop(n-1,k,target-i,dp)%MOD;

        }
        dp[n][target]=ans%MOD;
        return dp[n][target];
    }
    int solveUsingTab(int n,int k,int target)
    {
        vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,0));
        dp[0][0]=1;
        
        for(int i=1;i<=n;i++)
        {
            for(int j=1;j<=target;j++)
            {
                long long int ans=0;
                for(int m=1;m<=k;m++)
                {
                    long long int recAns=0;
                    if(j-m>=0)
                     recAns=recAns%MOD+dp[i-1][j-m]%MOD;
                ans=(ans%MOD +recAns%MOD)%MOD;
                }
                dp[i][j]=ans;
            }
        }
        return dp[n][target];


    }
    int numRollsToTarget(int n, int k, int target) {
        //base
        //    return solveUsingRec(n,k,target);

        // vector<vector<long long int>>dp(n+1,vector<long long int>(target+1,-1));
        // return solveUsingTop(n,k,target,dp);


        return solveUsingTab(n,k,target);
    }
};