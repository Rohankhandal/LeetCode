class Solution {
public:
bool solve(vector<int>&nums,int target,int i)
{
    if(i>=nums.size()) return false;
    if(target<0) return 0;
    if(target==0) return 1;

    bool include=solve(nums,target-nums[i],i+1);
    bool exclude=solve(nums,target,i+1);

    return include||exclude;
}
bool solveMem(vector<int>&nums,int target,int i,vector<vector<int>>&dp)
{
    if(i>=nums.size()) return 0;
    if(target<0) return 0;
    if(target==0) return 1;

    if(dp[i][target]!=-1) return dp[i][target];

    bool include=solveMem(nums,target-nums[i],i+1,dp);
    bool exclude=solveMem(nums,target,i+1,dp);

    dp[i][target]=include||exclude;

    return dp[i][target];

}
bool solveTab(vector<int>&nums,int target)
{
    vector<vector<int>>dp(nums.size()+1,vector<int>(target+1,0));

    for(int i=0;i<nums.size();i++)
    {
        dp[i][0]=1;
    }

    for(int i=nums.size()-1;i>=0;i--)
    {
        for(int t=1;t<=target;t++)
        {
            bool include=0;
            if(t-nums[i]>=0)
            {
                include=dp[i+1][t-nums[i]];
            }
            bool exclude=dp[i+1][t];

            dp[i][t]=include||exclude;
        }
    }

    return dp[0][target];

}
    bool canPartition(vector<int>& nums) {
        int sum=0;
        for(auto &it:nums)
        {
            sum+=it;
        }
        if(sum%2!=0) return false;
        
        // return solve(nums,sum/2,0);

        // using MEM
        int n=nums.size();
        int target=sum/2;
        // vector<vector<int>>dp(n,vector<int>(target+1,-1));
        // return solveMem(nums,target,0,dp);


        //using bottomm
        return solveTab(nums,target);
    }


};