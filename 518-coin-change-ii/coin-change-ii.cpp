// e.g:- 1,1,1,2 and 2,1,1,1 are same {that's why we don't use for loop}

//Approach-1 (Recursion + Mempozation) : O(n*amount)
class Solution {
public:
    int n;
    int t[301][5001];
    

    // int solve(int i, vector<int>& coins, int amount) {
        
    //     if(amount == 0)
    //         return t[i][amount] = 1;
        
    //     if(i == n || amount < 0)
    //         return 0;
        
    //      if(t[i][amount] != -1)
    //         return t[i][amount];
        
    //     if(coins[i] > amount)
    //         return t[i][amount] = solve(i+1, coins, amount);
        
    //     int take = solve(i, coins, amount-coins[i]);
    //     int skip = solve(i+1, coins, amount);
        
    //     return t[i][amount] = take+skip;
        
    // }
    

   int solveTab(vector<int>& coins, int amt) {
        int n=coins.size();
        vector<vector<int>>dp(n+1,vector<int>(amt+1,0));
        
        for(int i=0;i<n;i++){
            dp[i][0]=1;
        }
       
        for(int i=n-1;i>=0;i--)
        {
            for(int amount=1;amount<=amt;amount++)
            {
                int take=0;
                if(amount>=coins[i])
                    take = dp[i][amount-coins[i]];
                int skip = dp[i+1][amount];
                
                dp[i][amount] = take+skip;
            }
        }
        return dp[0][amt];
       
        
    }
    int change(int amount, vector<int>& coins) {
        n = coins.size();
        // memset(t, -1, sizeof(t));
        // return solve(0, coins, amount);

        return solveTab(coins,amount);

    }
};