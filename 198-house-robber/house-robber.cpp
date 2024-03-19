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
//Bottom Up
int solveUsingBottomUp(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>dp(nums.size()+1,0);
        dp[0]=nums[0];

        for(int i=1;i<n;i++)
        {
            int temp=0;
            if(i-2>=0) temp=dp[i-2];
            int include=temp+nums[i];
            int exclude=0+dp[i-1];
            dp[i]=max(include,exclude);
        }
        return dp[n-1];
        
}

//Space optimization
int spaceOpt(vector<int>&nums)
    {
        int n=nums.size();
        
        int prev2=0;
        int prev1=nums[0];
        int curr=0;

        for(int i=1;i<=n;i++)
        {
            int temp=0;
            if(i-2>=0)
                temp=prev2;
            int include=temp+nums[i];
            int exclude=0+prev1;
            curr=max(include,exclude);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;
        
}
    
    int rob(vector<int>& nums) {
        // vector<int>dp(nums.size()+1,-1);  //at index i how much maximum amount we can robb
        // return solveUsingTopDown(nums,nums.size()-1,dp);
        
        return solveUsingBottomUp(nums);
    }
};