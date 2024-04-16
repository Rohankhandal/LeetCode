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
    int space(vector<int>nums)
    {
        int n=nums.size();
        vector<int>first(n+1,0);
        vector<int>next(n+1,0);
        //bcz prev =-1 , so then index is invalid , so we replace prev => prev+1;

        for(int curr=n-1;curr>=0;curr-- )
        {
            for(int prev=curr-1;prev>=-1;prev--)
            {
                int include=0;
                if(prev==-1  || nums[curr]>nums[prev]){
                    include=1+next[curr+1];
                }
                int exclude=0+next[prev+1];

                first[prev+1]=max(include,exclude);
               
            }
            next=first;
        }
        return next[-1+1];
        
    }

    int binarySearch(vector<int>&nums)
    {
        if(nums.size()==0) return 0;
        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]>ans.back())
            {
                ans.push_back(nums[i]);
            }
            else
            {
                //overwrite 
                //find the index of just greater element
                int index=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[index]=nums[i];
            }
        }
        return ans.size();

    }
    int lengthOfLIS(vector<int>& nums) {
        // return solve(nums,0,-1);

        // vector<vector<int>>dp(nums.size()+1,vector<int>(nums.size()+1,-1));
        // return solveTop(nums,0,-1,dp);

        // return solveTab(nums);
        // return space(nums);

        return binarySearch(nums);
    }
};