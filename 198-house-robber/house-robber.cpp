class Solution {
public:
//recursion
    int solve(vector<int>&nums,int i)
    {
        if(i<0)
        {
            return 0;
        }

        int include=nums[i]+solve(nums,i-2);
        int exclude=0+solve(nums,i-1);

        return max(include,exclude);
    }
//Top Down
    int solveUsingTopDown(vector<int>&nums,int i,vector<int>&dp)
    {
        if(i<0)
        {
            return 0;
        }
        if(i==0)
            return nums[0];
        if(dp[i]!=-1) return dp[i];

        int include=nums[i]+solveUsingTopDown(nums,i-2,dp);
        int exclude=0+solveUsingTopDown(nums,i-1,dp);

        dp[i]=max(include,exclude);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);  //at index i how much maximum amount we can robb
        return solveUsingTopDown(nums,nums.size()-1,dp);
        //  dp[n-1];
    }
};