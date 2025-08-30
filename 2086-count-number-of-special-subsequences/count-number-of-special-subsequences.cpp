class Solution {
public:
    int MOD=1e9+7;
    int func(int ind, int last, vector<int>& nums, vector<vector<int>>& dp){
        if(ind==nums.size()){
            if(last==2)return 1;
            return 0;
        }

        if(dp[ind][last+1]!=-1)return dp[ind][last+1];

        long long notTake=func(ind+1,last,nums,dp)%MOD;
        long long take=0;

        if(last==-1){
            if(nums[ind]==0)take=(func(ind+1,0,nums,dp))%MOD;
        }
        if(last==0){
            if(nums[ind]==0 || nums[ind]==1){
                take=func(ind+1,nums[ind],nums,dp)%MOD;
            }
        }
        if(last==1){
            if(nums[ind]==1 || nums[ind]==2){
                take=func(ind+1,nums[ind],nums,dp)%MOD;
            }
        }
        if(last==2){
            if(nums[ind]==2){
                take=func(ind+1,2,nums,dp)%MOD;
            }
        }

        return dp[ind][last+1]= (take+notTake)%MOD;
    }
    int countSpecialSubsequences(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>>dp(n,vector<int>(4,-1));
        return func(0,-1,nums,dp)%MOD;

    }
};