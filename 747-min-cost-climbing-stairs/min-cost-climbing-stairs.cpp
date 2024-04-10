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
    int minCostClimbingStairs(vector<int>& cost) {
        int n=cost.size();
        // return min(solve(cost,n-1),solve(cost,n-2));

        vector<int>dp(n,-1);
        return min(solveTop(cost,n-1,dp),solveTop(cost,n-2,dp));
    }
};