class Solution {
public:
    int f(int i,vector<int>&nums,int s1,int total, vector<vector<int>>&dp){
        if(i>=nums.size()) 
        {
            int s2=total-s1;
            return s1==s2;
        }
        if(dp[i][s1]!=-1) return dp[i][s1];

        int take=f(i+1,nums,s1+nums[i],total,dp);
        int skip=f(i+1,nums,s1,total,dp);

        return dp[i][s1]=(take||skip);
    }
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int total=accumulate(nums.begin(),nums.end(),0);
        vector<vector<int>>dp(n,vector<int>(total+1,-1));
        return f(0,nums,0,total,dp);
    }
};