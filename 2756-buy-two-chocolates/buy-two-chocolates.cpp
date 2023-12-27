class Solution {
public:
    int buyChoco(vector<int>& prices, int money) {
        sort(prices.begin(),prices.end());
        for(int i=0;i<prices.size()-1;i++)
        {
            int sum=prices[i]+prices[i+1];
            if(sum<=money)
            {
                money-=sum;
                break;
            }
        }
        return money;
    }
};