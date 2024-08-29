class Solution {
public:
    long long solve(vector<int>&nums,int i,int sign)
    {
        if(i>=nums.size()) return 0;

        //take 
        long long take1=nums[i]*sign+solve(nums,i+1,sign*-1);

        long long skip=solve(nums,i+1,sign);

        return max(take1,skip);
    }

    long long solveMem(vector<int>&nums,int i,int sign, vector<vector<long long>>&dp)
    {
        if(i>=nums.size()) return 0;

        if(dp[i][sign]!=-1) return dp[i][sign];
        //take 
        long long take=0;
        if(sign==0)  //0 means minus
            take= -nums[i]+solveMem(nums,i+1,1,dp);
        else
            take= nums[i]+solveMem(nums,i+1,0,dp);

        long long skip=solveMem(nums,i+1,sign,dp);

        return dp[i][sign]=max(take,skip);
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int sign=1;
        int n=nums.size();
        // return solve(nums,0,sign);


        vector<vector<long long>>dp(n,vector<long long>(2,-1));
        return solveMem(nums,0,sign,dp);    //sign=0 means minus and sign=1 means plus
    }
};