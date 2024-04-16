class Solution {
public:
    int solve(vector<int>nums,int i,int prev)
    {
        if(i>=nums.size()) return 0;

        int include=0;
        if(prev==-1  || nums[i]>nums[prev]){
            include=1+solve(nums,i+1,i);
        }
        int exclude=0+solve(nums,i+1,prev);

        return max(include,exclude);
    }
    int solveTop(vector<int>nums,int i,int prev,vector<vector<int>>&dp)
    {
        //bcz prev =-1 , so then index is invalid , so we replace prev => prev+1;
        if(i>=nums.size()) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];

        int include=0;
        if(prev==-1  || nums[i]>nums[prev]){
            include=1+solveTop(nums,i+1,i,dp);
        }
        int exclude=0+solveTop(nums,i+1,prev,dp);

       dp[i][prev+1]=max(include,exclude);
       return dp[i][prev+1];
    }
    int solveTab(vector<int>nums)
    {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        //bcz prev =-1 , so then index is invalid , so we replace prev => prev+1;

        for(int curr=n-1;curr>=0;curr-- )
        {
            for(int prev=curr-1;prev>=-1;prev--)
            {
                int include=0;
                if(prev==-1  || nums[curr]>nums[prev]){
                    include=1+dp[curr+1][curr+1];
                }
                int exclude=0+dp[curr+1][prev+1];

                dp[curr][prev+1]=max(include,exclude);
               
            }
        }
        return dp[0][-1+1];
        
    }
    int lengthOfLIS(vector<int>& nums) {
        // return solve(nums,0,-1);

        // vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        // return solveTop(nums,0,-1,dp);

        return solveTab(nums);
    }
};