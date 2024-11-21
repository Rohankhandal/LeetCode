class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minPrice=prices[0];
        int maxProfit=INT_MIN;
        for(int i=1;i<n;i++)
        {
            int todayProfit=prices[i]-minPrice;
            maxProfit=max(todayProfit,maxProfit);

            minPrice=min(minPrice,prices[i]);
        }
        return maxProfit<0?0:maxProfit;
    }
};