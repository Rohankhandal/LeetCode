class Solution {
public:
     int solve(vector<int>&coins,int amount,int i)
    {
       if(i==coins.size()-1)
       {
          if(amount%coins[i]==0) return 1;  //we can take infinite no. of times
          else return 0;
       }

       int take=0;
        if(coins[i]<=amount)
        take=solve(coins,amount-coins[i],i);

        int noTake=solve(coins,amount,i+1);

        return take+noTake;

    }

    int solveMem(vector<int>&coins,int amount,int i,vector<vector<int>>&dp)
    {
        if(dp[i][amount]!=-1) return dp[i][amount];

       if(i==coins.size()-1)
       {
          if(amount%coins[i]==0) return 1;  //we can take infinite no. of times
          else return 0;
       }

       int take=0;
        if(coins[i]<=amount)
        take=solveMem(coins,amount-coins[i],i,dp);

        int noTake=solveMem(coins,amount,i+1,dp);

        return dp[i][amount]=take+noTake;

    }


    int solveTab(vector<int>&coins,int amt)
    {
        int n =coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amt+1,0));
      
        for(int amount=0;amount<=amt;amount++)
        {
            dp[n-1][amount]=(amount%coins[n-1]==0);
        }
      
        for(int amount=0;amount<=amt;amount++)
        {
            for(int i=n-2;i>=0;i--)
            {
                int take=0;
                if(coins[i]<=amount)
                take=dp[i][amount-coins[i]];

                int noTake=dp[i+1][amount];

                dp[i][amount]=take+noTake;
            }
        }

        return dp[0][amt];

       

    }
   
    int change(int amount, vector<int>& coins) {
        // return solve(coins,amount,0);

        // 2.Memoziation
        int n=coins.size();
        // vector<vector<int>>dp(n+1,vector<int>(amount+1,-1));
        // return solveMem(coins,amount,0,dp);

        // 3.Tabluation
        return solveTab(coins,amount);
    }
};


