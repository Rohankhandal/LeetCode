class Solution {
public:
    int solve(int i,vector<int>&prices,int buy,int cnt,vector<vector<vector<int>>>&dp)
    {
        if(i>=prices.size() || cnt==2) return 0;
        if(dp[i][buy][cnt]!=-1) return dp[i][buy][cnt]; 
        int profit=0;
        if(buy)
        {
            int buy=-prices[i]+solve(i+1,prices,0,cnt,dp);
            int skipKaro=solve(i+1,prices,1,cnt,dp);
            profit=max(buy,skipKaro);
        }
        else
        {
            int sell=prices[i]+solve(i+1,prices,1,cnt+1,dp);
            int skipKaro=solve(i+1,prices,0,cnt,dp);
            profit=max(sell,skipKaro);
        }
        return dp[i][buy][cnt]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int buy=1;
       vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));



        return solve(0,prices,buy,0,dp);
    }
};