class Solution {
public:
    int solve(int i,vector<int>&prices,int buy,vector<vector<int>>&dp)
    {
        if(i>=prices.size()) return 0;
        
        if(dp[i][buy]!=-1) return dp[i][buy];
        
        int profit=0;
        if(buy)
        {
            int buy=-prices[i]+solve(i+1,prices,0,dp);
            int skip=solve(i+1,prices,1,dp);
            profit=max(buy,skip);
        }
        else 
        {
            int sellKaro=prices[i]+solve(i+1,prices,1,dp);
            int skipKaro=solve(i+1,prices,0,dp);
            profit=max(sellKaro,skipKaro);
            
        }
        return dp[i][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        //mutiple buy and sell allowed
        // 1->buy and 0->sell
         vector<vector<int>>dp(n,vector<int>(2,-1));
        return solve(0,prices,1,dp);
        
    }
};