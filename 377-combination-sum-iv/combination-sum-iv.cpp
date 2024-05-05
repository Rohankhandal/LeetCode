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

    //3.Tabluation
    int solveTab(vector<int>&nums,int t)
    {
        vector<int>dp(t+1,0);
        int n=nums.size();
        dp[0]=1;
        
        for(int tar=1;tar<=t;tar++)
        {
            long long ans=0;      //IMP (long long imp)
            for(int i=n-1;i>=0;i--)
            {
                if(tar-nums[i]>=0)
                ans+=dp[tar-nums[i]];
            }
            dp[tar]=ans;
        }
        return dp[t];
    }
    int combinationSum4(vector<int>& nums, int target) {
        // int i=0;
        // return solve(nums,target);

        //2.Memoziation
        // vector<int>dp(target+1,-1);
        // return solveMem(nums,target,dp);


        //3.Tabluation
        return solveTab(nums,target);
    }
};