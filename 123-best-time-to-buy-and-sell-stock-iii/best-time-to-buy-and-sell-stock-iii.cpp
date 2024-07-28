
class Solution {
public:
    // buy=>1 means you can buy
    // buy=>0 means you can sell

    int solve(vector<int>&prices,int i,int buy,int limit)
    {
        if(i>=prices.size()) return 0;  //profit=sell-buy => sell+(-buy)

        if(limit==0) return 0;

        int ans=0;
        if(buy) //you can buy
        {
            int take=-prices[i]+solve(prices,i+1,0,limit);
            int skip=0+solve(prices,i+1,buy,limit);

            ans=max(take,skip);
        }
        else
        {
            int take=prices[i]+solve(prices,i+1,1,limit-1);
            int skip=0+solve(prices,i+1,buy,limit);

            ans=max(take,skip);
        }

        return ans;
    }

    //2.Memoziation
    int solveMem(vector<int>&prices,int i,int buy,int limit,vector<vector<vector<int>>>&dp)
    {
        if(i>=prices.size()) return 0;  //profit=sell-buy => sell+(-buy)

        if(limit==0) return 0;
        if(dp[i][buy][limit]!=-1) return dp[i][buy][limit];

        int ans=0; 
        if(buy) //you can buy
        {
            int take=-prices[i]+solveMem(prices,i+1,0,limit,dp);
            int skip=0+solveMem(prices,i+1,buy,limit,dp);

            ans=max(take,skip);
        }
        else
        {
            int take=prices[i]+solveMem(prices,i+1,1,limit-1,dp);
            int skip=0+solveMem(prices,i+1,buy,limit,dp);

            ans=max(take,skip);
        }

        return dp[i][buy][limit]=ans;
    }


    //3.Tabluation
    int solveTab(vector<int>&prices)
    {
        int n=prices.size(); 
        int l=2;  //limit
         vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(l+1,0)));


        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int limit=1;limit<=l;limit++)
                {
                    int ans=0; 
                    if(buy) //you can buy
                    {
                        int take=-prices[i]+dp[i+1][0][limit];
                        int skip=0+dp[i+1][buy][limit];

                        ans=max(take,skip);
                    }
                    else
                    {
                        int take=prices[i]+dp[i+1][1][limit-1];
                        int skip=0+dp[i+1][buy][limit];

                        ans=max(take,skip);
                    }
                    dp[i][buy][limit]=ans;
                }
                 
            }
        }
        return dp[0][1][2];
        
    }

    //4.space
    
    int space(vector<int>&prices)
    {
        int n=prices.size(); 
        int l=2;  //limit
        //  vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2,vector<int>(l+1,0)));
        vector<vector<int>>curr(2,vector<int>(l+1,0));
        vector<vector<int>>next(2,vector<int>(l+1,0));


        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                for(int limit=1;limit<=l;limit++)
                {
                    int ans=0; 
                    if(buy) //you can buy
                    {
                        int take=-prices[i]+next[0][limit];
                        int skip=0+next[buy][limit];

                        ans=max(take,skip);
                    }
                    else
                    {
                        int take=prices[i]+next[1][limit-1];
                        int skip=0+next[buy][limit];

                        ans=max(take,skip);
                    }
                    curr[buy][limit]=ans;
                }
                 
            }
            next=curr;
        }
        return next[1][2];
        
    }
    int maxProfit(vector<int>& prices) {
        // int buy=1;  //first buy it and then sell it
        // int limit=2;
        // return solve(prices,0,buy,limit);

        // 2.Memozaiton
        // int n=prices.size();
        // int limit=2;
        // vector<vector<vector<int>>>dp(n,vector<vector<int>>(2,vector<int>(limit+1,-1)));
        // return solveMem(prices,0,1,limit,dp);


        // 3.Memoziation
        // return solveTab(prices);

        

         // 4.space
        return space(prices);
    }
};