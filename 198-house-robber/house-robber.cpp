class Solution {
public:
    int solve(vector<int>&nums,int i)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        int include=nums[i]+solve(nums,i+2);
        int exclude=0+solve(nums,i+1);

        return max(include,exclude);
    }
    int solveUsingMem(vector<int>&nums,int i,vector<int>&dp)
    {
        if(i>=nums.size())
        {
            return 0;
        }
        if(dp[i]!=-1)
        {
            return dp[i];
        }
        int include=nums[i]+solveUsingMem(nums,i+2,dp);
        int exclude=0+solveUsingMem(nums,i+1,dp);

        dp[i]=max(include,exclude);
        return dp[i];
    }
    int rob(vector<int>& nums) {
        // return solve(nums,0);

        vector<int>dp(nums.size()+1,-1);
        return solveUsingMem(nums,0,dp);
    }
};