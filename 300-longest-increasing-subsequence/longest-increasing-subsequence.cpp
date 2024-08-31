class Solution {
public:
    int solve(vector<int>&nums,int i,int prev,vector<vector<int>>&dp)
    {
        int n=nums.size();
        if(i>=n) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=INT_MIN;
        if(prev==-1 || nums[prev]<nums[i])
        {
            take=1+solve(nums,i+1,i,dp);
        }

        int skip=solve(nums,i+1,prev,dp);

        return dp[i][prev+1]=max(take,skip);
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        return solve(nums,0,-1,dp);
    }
};