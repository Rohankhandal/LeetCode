class Solution {
public:
    int solveMem(vector<int>&coins,int amount,vector<int>&dp)
    {
        // if(i>=coins.size()) return INT_MAX;
        if(amount==0) return 0;
        if(amount<0) return INT_MAX;

        if(dp[amount]!=-1) return dp[amount];

        int ans=INT_MAX;
        for(int i=0;i<coins.size();i++)
        {
            int res=solveMem(coins,amount-coins[i],dp);

            if(res!=INT_MAX)
                ans=min(ans,1+res);
        }

        return dp[amount]=ans;

    }


    //2.Tabluation
    int solveTab(vector<int>&coins,int amt)
    {
        vector<int>dp(amt+1,0);

        for(int amount=1;amount<=amt;amount++)
        {
            int ans=INT_MAX;
            for(int i=0;i<coins.size();i++)
            {
                int res=INT_MAX;

                if(amount-coins[i]>=0)
                    res=dp[amount-coins[i]];

                if(res!=INT_MAX)
                    ans=min(ans,1+res);
            }
            dp[amount]=ans;
        }
        

        return dp[amt]!=INT_MAX?dp[amt]:-1;

    }
    int coinChange(vector<int>& coins, int amount) {
        // int res=solve(coins,amount);   
        // return res!=INT_MAX?res:-1;

        // vector<int>dp(amount+1,-1);
        // int res=solveMem(coins,amount,dp);   
        // return res!=INT_MAX?res:-1;


        return solveTab(coins,amount);
        
    }
};