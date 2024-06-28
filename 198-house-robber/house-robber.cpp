class Solution {
public:
    int dp[101];
     int solve(vector<int>&nums,int i)
     {
        if(i>=nums.size()) return 0;

        int take=nums[i]+solve(nums,i+2);
        int notake=0+solve(nums,i+1);
        return max(take,notake);
     }
     //2.Memoziation
     int solveMem(vector<int>&nums,int i)
     {
        if(i>=nums.size()) return 0;
        if(dp[i]!=-1) return dp[i];

        int take=nums[i]+solveMem(nums,i+2);
        int notake=0+solveMem(nums,i+1);

        return dp[i]=max(take,notake);
     }
    int rob(vector<int>& nums) {
        memset(dp,-1,sizeof(dp));
        return solveMem(nums,0);
    }
};