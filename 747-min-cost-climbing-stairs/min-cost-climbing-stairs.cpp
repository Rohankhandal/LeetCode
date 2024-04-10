class Solution {
public:
    int solve(vector<int>&cost,int n)
    {
        if(n==0)
        {
            return cost[0];
        }
        if(n<0)
        {
            return 0;
        }
        return cost[n]+min(solve(cost,n-1),solve(cost,n-2));
    }
    int solveTop(vector<int>&cost,int n,vector<int>&dp)
    {
        if(n==0)
        {
            return cost[0];
        }
        if(n<0)
        {
            return 0;
        }
        if(dp[n]!=-1) return dp[n];
        return dp[n]=cost[n]+min(solveTop(cost,n-1,dp),solveTop(cost,n-2,dp));
    }
    int solveBottom(vector<int>&cost)
    {
        int n=cost.size();
        vector<int>dp(n,0);
        dp[0]=cost[0];

        for(int i=1;i<n;i++)
        {
            int val2=0;
            if(i-2>=0)
            {
                val2=dp[i-2];
            }
            dp[i]=cost[i]+min(dp[i-1],val2);
        }
        return min(dp[n-1],dp[n-2]);
    }
    int space(vector<int>&cost)
    {
        int n=cost.size();
        int prev2=cost[0];
        int prev1=cost[1];
        int curr=0;
        for(int i=2;i<n;i++)
        {
            curr=cost[i]+min(prev1,prev2);

            prev2=prev1;
            prev1=curr;
        }
        return min(prev1,prev2);
    }

    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        // return min(solve(cost,n-1),solve(cost,n-2));

        // vector<int>dp(n,-1);
        // return min(solveTop(cost,n-1,dp),solveTop(cost,n-2,dp));

        // return solveBottom(cost);

        return space(cost);
    }
};