//Recursive Approach
class Solution {
public:
    void findMaxProfit(vector<int>&prices,int i,int &minValue,int &maxiProfit)
    {
        if(i>=prices.size()) return ;

        if(prices[i]<minValue) minValue=prices[i];

        int todayProfit=prices[i]-minValue;
        if(maxiProfit<todayProfit) maxiProfit=todayProfit;

        findMaxProfit(prices,i+1,minValue,maxiProfit);

    }
    int maxProfit(vector<int>& prices) {
        int minValue=INT_MAX,maxiProfit=INT_MIN;
        int n=prices.size();
        findMaxProfit(prices,0,minValue,maxiProfit);
        return maxiProfit;
    }
};

//ITERATIVE APPROACH

// class Solution {
// public:
//     int maxProfit(vector<int>& prices) {
//         int minValue=INT_MAX,maxi=INT_MIN;
//         int n=prices.size();
//         for(int i=0;i<n;i++)
//         {
//             if(prices[i]<minValue) minValue=prices[i];

//             int todayProfit=prices[i]-minValue;
//             if(maxi<todayProfit) maxi=todayProfit;
//         }
//         return maxi;
//     }
// };