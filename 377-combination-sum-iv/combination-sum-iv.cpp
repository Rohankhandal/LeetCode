class Solution {
public:
    int solve(vector<int>&nums,int tar)
    {
        if(tar==0) return 1;
        if(tar<0) return 0;
        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=solve(nums,tar-nums[i]);   
        }
        return ans;
    }
    int solveTop(vector<int>&nums,int tar,vector<int>&dp)
    {
        if(tar==0) return 1;
        if(tar<0) return 0;
        if(dp[tar]!=-1) return dp[tar];

        int ans=0;
        for(int i=0;i<nums.size();i++)
        {
            ans+=solveTop(nums,tar-nums[i],dp);   
        }
        return dp[tar]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        // return solve(nums,target);

        vector<int>dp(target+1,-1);
        return solveTop(nums,target,dp);
    }
};