class Solution {
public:
    int solve(vector<int>&arr,int i,int sum, vector<vector<int>>&dp)
    {
        if(sum>arr.back()) return sum;       //IMP otherwise Given MLE
       if (i >= arr.size()) {
            return sum;
        }

        if(dp[i][sum] != -1) {
            return dp[i][sum];
        }

        // Include the current element if it's greater than the current sum
        int take = 0;
        if (arr[i] > sum)
            take = solve(arr, i + 1, sum + arr[i], dp);
        
        // Exclude the current element
        int noTake = solve(arr, i + 1, sum, dp);

        // Memoize the result for the current index and sum
        dp[i][sum] = max(take, noTake);

        return dp[i][sum];
    }
    

    int maxTotalReward(vector<int>& rewardValues) {
        sort(rewardValues.begin(),rewardValues.end());
         int n = rewardValues.size();
        
        vector<vector<int>> dp(n + 1, vector<int>(rewardValues.back() + 1, -1));
        return solve(rewardValues, 0, 0, dp);
        
    }
};