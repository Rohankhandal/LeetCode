class Solution {
public:
    //4.space
    int space(vector<int>&prices,int fee)
    {
        int n=prices.size();
        //  vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>curr(2,0);
        vector<int>next(2,0);

        for(int i=n-1;i>=0;i--)
        {
            for(int buy=0;buy<=1;buy++)
            {
                 int ans=0; 
                if(buy) //you can buy
                {
                    int take=-prices[i]+next[0];
                    int skip=0+next[buy];

                    ans=max(take,skip);
                }
                else
                {
                    int take=prices[i]+next[1]-fee;
                    int skip=0+next[buy];

                    ans=max(take,skip);
                }
                 curr[buy]=ans;
            }
            next=curr;
        }
        return next[1];
        
    }
    int maxProfit(vector<int>& prices,int fee) {

         // 4.space
        return space(prices,fee);  //when we sell a stock deduct the fee from prices
    }
};