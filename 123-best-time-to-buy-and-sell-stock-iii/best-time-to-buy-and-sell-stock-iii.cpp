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


    //2.Memoziation
    int solveMem(vector<int>& prices) {
    int n = prices.size();
    // DP array: dp[i][buy][cnt]
    vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(2+1, vector<int>(2+1, 0)));

    // Iterate from the last day to the first
    for (int i = n - 1; i >= 0; i--) {
        for (int buy = 1; buy >= 0; buy--) {
            for (int cnt = 1; cnt >= 0; cnt--) {
                int profit = 0;
                if (buy) {
                    int buyStock = -prices[i] + dp[i+1][0][cnt];
                    int skip = dp[i+1][1][cnt];
                    profit = max(buyStock, skip);
                } else {
                    int sellStock = prices[i] + dp[i+1][1][cnt+1];
                    int skip = dp[i+1][0][cnt];
                    profit = max(sellStock, skip);
                }
                dp[i][buy][cnt] = profit;
            }
        }
    }
    return dp[0][1][0]; // Start from day 0, buying allowed, and 0 transactions done
}


    int maxProfit(vector<int>& prices) {
    //     int n=prices.size();
    //     int buy=1;
    //    vector<vector<vector<int>>> dp(n, vector<vector<int>>(2, vector<int>(2, -1)));

    //     return solve(0,prices,buy,0,dp);


        return  solveMem(prices);
    }
};