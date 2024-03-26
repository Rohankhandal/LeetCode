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
    int solveUsingTab(vector<int>&nums,int i)
    {
        vector<int>dp(nums.size()+1,0);
        int n=nums.size();
        dp[n]=0;
        
        for(int i=n-1;i>=0;i--)
        {
            int include=nums[i];
            if(i+2<=n)
            {
                include+=dp[i+2];
            }    
            int exclude=0+dp[i+1];

            dp[i]=max(include,exclude);
        }

        return dp[0];
    }
    int space(vector<int>&nums,int i)
    {
        int n=nums.size();
        int prev2=0;
        int prev1=nums[n-1];
        int curr=0;
        for(int i=n-2;i>=0;i--)
        {
            int include=nums[i];
            if(i+2<=n)
            {
                include+=prev2;
            }    
            int exclude=0+prev1;

            curr=max(include,exclude);

            prev2=prev1;
            prev1=curr;
        }
        return prev1;
    }
    int rob(vector<int>& nums) {
        // return solve(nums,0);

        // vector<int>dp(nums.size()+1,-1);
        // return solveUsingMem(nums,0,dp);
        int n=nums.size();
        return space(nums,n-1);
    }
};