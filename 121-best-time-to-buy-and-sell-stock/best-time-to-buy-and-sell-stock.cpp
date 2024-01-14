class Solution {
public:
    int maxProfit(vector<int>& prices) {
       int maxi=INT_MIN,maxPos=0;
       int mini=INT_MAX,minPos=0;
       for(int i=0;i<prices.size();i++)
       {
          if(prices[i]<mini)  mini=prices[i];

          int todayProfit=prices[i]-mini;
          if(todayProfit>maxi)   maxi=todayProfit;
           
       }

       return maxi;
       


    }
};

//recursive approach

// class Solution {
// public:
//     void maxProfitFinder(vector<int> &prices , int i, int &minPrice, int &maxProfit)
//     {
//         //base
//         if(i == prices.size()) return ;

//         //sol for one case
//         if(prices[i] < minPrice) minPrice = prices[i];
//          int todayProfit = prices[i] - minPrice;
//          if(todayProfit > maxProfit )  maxProfit = todayProfit;


//          //RE
//          maxProfitFinder(prices, i+1, minPrice, maxProfit);
//     }


//     int maxProfit(vector<int>& prices) {
//         int minPrice=INT_MAX;
//         int maxProfit=INT_MIN;
//         maxProfitFinder(prices,0,minPrice,maxProfit);

//         return maxProfit;
//     }
// };

