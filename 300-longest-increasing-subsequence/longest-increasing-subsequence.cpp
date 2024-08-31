class Solution {
public:
    int solve(vector<int>&nums,int i,int prev,vector<vector<int>>&dp)
    {
        int n=nums.size();
        if(i>=n) return 0;

        if(dp[i][prev+1]!=-1) return dp[i][prev+1];
        int take=INT_MIN;
        if(prev==-1 || nums[prev]<nums[i])
        {
            take=1+solve(nums,i+1,i,dp);
        }

        int skip=solve(nums,i+1,prev,dp);

        return dp[i][prev+1]=max(take,skip);
    }


    //2.Tabluation
    int solveTab(vector<int>&nums)
    {
        int n=nums.size();
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));


        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                int take=INT_MIN;
                if(prev==-1 || nums[prev]<nums[i])
                {
                    take=1+dp[i+1][i+1];
                }

                int skip=dp[i+1][prev+1];

                dp[i][prev+1]=max(take,skip);
            }
        }

        return dp[0][-1+1];
        
    }


    //simplest Tablaution
    int f(vector<int>&nums)
    {
        int n=nums.size();
        vector<int>dp(n+1,1);
        int maxi=1;  //individual element are also a single element LIS
        for(int i=0;i<n;i++)
        {
            for(int prev=0;prev<=i-1;prev++)
            {
                if(nums[prev]<nums[i])
                {
                    dp[i]=max(1+dp[prev],dp[i]);
                    maxi=max(dp[i],maxi);
                }
            }
        }

        for(int i=0;i<n;i++)
        {
            cout<<nums[i]<<" "<<dp[i]<<endl;
        }
        return maxi;
        

    }


    int binarySearch(vector<int>&nums)
    {
        int n=nums.size();

        vector<int>ans;
        ans.push_back(nums[0]);
        for(int i=1;i<n;i++)
        {
            if(ans.back()<nums[i])
            {
                ans.push_back(nums[i]);
            }
            else 
            {
                int idx=lower_bound(ans.begin(),ans.end(),nums[i])-ans.begin();
                ans[idx]=nums[i];
            }
        }
        return ans.size();
    }
    int lengthOfLIS(vector<int>& nums) {
        int n=nums.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return solve(nums,0,-1,dp);


        // return solveTab(nums);


        // return f(nums);


        return binarySearch(nums);
    }
};