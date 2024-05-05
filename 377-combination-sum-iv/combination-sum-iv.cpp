class Solution {
public:
    int solve(vector<int>&nums,int tar)
    {
        int n=nums.size();
        if(tar==0) return 1;
        if(tar<0) return 0;
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=solve(nums,tar-nums[i]);
        }
        return ans;
    }
     int solveMem(vector<int>&nums,int tar,vector<int>&dp)
    {
        int n=nums.size();
        if(tar==0) return 1;
        if(tar<0) return 0;

        if(dp[tar]!=-1) return dp[tar];
        int ans=0;
        for(int i=0;i<n;i++)
        {
            ans+=solveMem(nums,tar-nums[i],dp);
        }
        return dp[tar]=ans;
    }
    int combinationSum4(vector<int>& nums, int target) {
        // int i=0;
        // return solve(nums,target);

        //2.Memoziation
        vector<int>dp(target+1,-1);
        return solveMem(nums,target,dp);
    }
};