class Solution {
public:
    int f(int idx,int amount,vector<int>&coins, vector<vector<int>>&dp)
    {
        if(amount==0) return 1;
        if(amount<0) return INT_MAX;
        if(idx>=coins.size()) return 0;

        if(dp[idx][amount]!=-1) return dp[idx][amount];

        int take=f(idx,amount-coins[idx],coins,dp);
        
        if(take==INT_MAX) take=0;

        int skip=f(idx+1,amount,coins,dp);

        if(skip==INT_MAX) skip=0;

        return dp[idx][amount]=take+skip;
    }
    int change(int amount, vector<int>& coins) {
        int n=coins.size();
        vector<vector<int>>dp(n,vector<int>(amount+1,-1));
        return f(0,amount,coins,dp);
    }
};