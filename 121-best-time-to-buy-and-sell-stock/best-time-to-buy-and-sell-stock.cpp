class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        int minPrice=INT_MAX;
        int maxProfit=INT_MIN;
        for(int i=0;i<n;i++)
        {
            minPrice=min(prices[i],minPrice);

            int todayProfit=prices[i]-minPrice;
            maxProfit=max(todayProfit,maxProfit);
        }
        return maxProfit;
    }
};