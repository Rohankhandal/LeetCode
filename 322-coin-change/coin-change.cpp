class Solution
{
    public:
       	// int solveUsingRecursion(vector<int>&coins,int amount)
       	// {
       	//     if(amount==0)
       	//     {
       	//         return 0;
       	//     }
       	//     if(amount < 0)
       	//     {
       	//         return INT_MAX;
       	//     }
       	//     int mini=INT_MAX;
       	//     for(int i=0;i < coins.size();i++)
       	//     {
       	//         int ans=solveUsingRecursion(coins,amount-coins[i]);
       	//         if(ans!=INT_MAX)
       	//         {
       	//             mini=min(mini,1+ans);
       	//         }
       	//     }
       	//     return mini;
       	// }
       	// int solveUsingTopDown(vector<int>&coins,int amount,vector<int>&dp)
       	// {
       	//     if(amount==0)
       	//     {
       	//         return 0;
       	//     }
       	//     if(amount < 0)
       	//     {
       	//         return INT_MAX;
       	//     }
       	//     if(dp[amount]!=-1)
       	//     {
       	//         return dp[amount];
       	//     }
       	//     int mini=INT_MAX;
       	//     for(int i=0;i < coins.size();i++)
       	//     {
       	//         int ans=solveUsingTopDown(coins,amount-coins[i],dp);
       	//         if(ans!=INT_MAX)
       	//         {
       	//             mini=min(mini,1+ans);
       	//         }
       	//     }
       	//     dp[amount]=mini;
       	//     return dp[amount];
       	// }

        int solveUsingBottomUp(vector<int> &coins, int amount)
        {
            int n = coins.size();
            vector<int> dp(amount + 1, INT_MAX);
            dp[0] = 0;
            if (amount == 0)
            {
                return dp[0];
            }
            for (int i = 1; i <= amount; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    if (i - coins[j] >= 0 && dp[i - coins[j]] != INT_MAX)
                    {
                        int ans = dp[i - coins[j]];
                        dp[i] = min(dp[i], ans + 1);
                    }
                }
            }
            return dp[amount];
        }
    int coinChange(vector<int> &coins, int amount)
    {
       	//  int ans= solveUsingRecursion(coins,amount);
       	//  if(ans!=INT_MAX)
       	//  {
       	//     return ans;
       	//  }
       	//  else
       	//  {
       	//     return -1;
       	//  }

       	// vector<int>dp(amount+1,-1);
       	// int ans=solveUsingTopDown(coins,amount,dp);
       	//  if(ans!=INT_MAX)
       	//  {
       	//     return ans;
       	//  }
       	//  else
       	//  {
       	//     return -1;
       	//  }

        int ans = solveUsingBottomUp(coins, amount);
        if (ans != INT_MAX)
        {
            return ans;
        }
        else
        {
            return -1;
        }
    }
};