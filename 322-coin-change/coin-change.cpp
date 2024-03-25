class Solution {
public:
    // int solve(vector<int>&coins,int amount)
    // {
    //     if(amount==0)
    //     {
    //         return  0;
    //     }
    //     if(amount<0)
    //     {
    //         return INT_MAX;
    //     }
    //     int ans=INT_MAX;
    //     for(int i=0;i<coins.size();i++)
    //     {
    //         int mini=solve(coins,amount-coins[i]);
    //         if(mini!=INT_MAX)
    //         {
    //             ans=min(ans,mini+1);
    //         }
    //     }
    //     return ans;
    // }
    int solveUsingMem(vector<int>&coins,int amount,vector<int>&dp)
    {
        if(amount==0)
        {
            dp[0]=0;
            return dp[0];
        }
        if(amount<0)
        {
            return INT_MAX;
        }
        if(dp[amount]!=-1)
        {
            return dp[amount];
        }
        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            int mini=solveUsingMem(coins,amount-coins[i],dp);
            if(mini!=INT_MAX)
            {
                ans=min(ans,mini+1);
            }
        }
        return dp[amount]=ans;
    }
    int coinChange(vector<int>& coins, int amount) {
        
        // int ans=solve(coins,amount);
        vector<int>dp(amount+1,-1);
        int ans=solveUsingMem(coins,amount,dp);
        if(ans==INT_MAX)
        {
            return -1;
        }
        else
        {
            return ans;
        }
    }
};