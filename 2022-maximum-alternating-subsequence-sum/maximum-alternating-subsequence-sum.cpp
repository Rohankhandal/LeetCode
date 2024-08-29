class Solution {
public:

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


    //3.Tabluationlong 
    long long  solveTab(vector<int>&nums)
    {
        int n=nums.size();
       vector<vector<long long>>dp(n+1,vector<long long>(2,0));

        for(int i=n-1;i>=0;i--)
        {
            for(int sign=1;sign>=0;sign--)
            {
                //take 
                long long take=0;
                if(sign==0)  //0 means minus
                    take = -nums[i]+dp[i+1][1];
                else
                    take = nums[i]+dp[i+1][0];

                long long skip=dp[i+1][sign];

                dp[i][sign]=max(take,skip);
            }
        }
        return dp[0][1];
    }
    long long maxAlternatingSum(vector<int>& nums) {
        int sign=1;
        int n=nums.size();
       
        //2.Memoziation
        // vector<vector<long long>>dp(n,vector<long long>(2,-1));
        // return solveMem(nums,0,sign,dp);    //sign=0 means minus and sign=1 means plus


        //3.Tabluation
        return solveTab(nums);
    }
};