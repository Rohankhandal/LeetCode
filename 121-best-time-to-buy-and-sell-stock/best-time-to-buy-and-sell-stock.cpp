class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int minValue=INT_MAX,maxi=INT_MIN;
        int n=prices.size();
        for(int i=0;i<n;i++)
        {
            if(prices[i]<minValue) minValue=prices[i];

            int todayProfit=prices[i]-minValue;
            if(maxi<todayProfit) maxi=todayProfit;
        }
        return maxi;
    }
};