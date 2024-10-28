class Solution {
public:
    int solve(int i,int prev,vector<int>&nums)
    {
        if(i>=nums.size()) return 0;

        int take=0;
        if(prev==-1 || ((nums[prev]*nums[prev])==nums[i]))
        {
            take=1+solve(i+1,i,nums);
        }

        int skip=0;
        skip=solve(i+1,prev,nums);

        return max(take,skip);
    }



    //Top-Down
    int solveMem(int i, int prev, vector<int>& nums, vector<vector<int>>& memo) {
        if (i >= nums.size()) return 0;
        if (memo[i][prev + 1] != -1) return memo[i][prev + 1]; // Check memo table

        int take = 0;
        if (prev == -1 || (nums[prev] * nums[prev] == nums[i])) {
            take = 1 + solveMem(i + 1, i, nums, memo);
        }

        int skip = solveMem(i + 1, prev, nums, memo);

        return memo[i][prev + 1] = max(take, skip); // Store result in memo table
    }


    //Bottom Up
    
    int solveTab(vector<int>& nums) {
        int n=nums.size();
        vector<vector<int>> dp(n+1, vector<int>(n + 1, 0)); 

        for(int i=n-1;i>=0;i--)
        {
            for(int prev=i-1;prev>=-1;prev--)
            {
                int take = 0;
                if (prev == -1 || (nums[prev] *1LL* nums[prev] == nums[i])) {
                    take = 1 + dp[i + 1][i+1];
                }

                int skip = dp[i + 1][prev+1];

                dp[i][prev + 1] = max(take, skip); 
            }
        }
        return dp[0][-1+1];
        
    }

    int space(vector<int>& nums) {
       int n = nums.size();
        vector<int> next(n + 1, 0);  // Stores the next row
        vector<int> curr(n + 1, 0);  // Stores the current row

        for (int i = n - 1; i >= 0; i--) {
            for (int prev = i - 1; prev >= -1; prev--) {
                int take = 0;
                // Check if we can take the current element based on square condition
                if (prev == -1 || (nums[prev] * 1LL * nums[prev] == nums[i])) {
                    take = 1 + next[i + 1];
                }

                // Option to skip the current element
                int skip = next[prev + 1];

                // Store the maximum of take and skip options
                curr[prev + 1] = max(take, skip);
            }
            next = curr;  // Move to the next row
        }
        
        // Return the result starting from the first element with no previous element
        return next[0];
        
    }

    //O(n*logN)
    int moreOptimize(vector<int>&nums)
    {
        sort(nums.begin(), nums.end());
        unordered_map<int, int> dp;  // Store the longest streak ending at each number
        int maxStreak = 0;

        for (int num : nums) {
            int squareRoot = sqrt(num);
            if (squareRoot * squareRoot == num && dp.count(squareRoot)) {
                dp[num] = dp[squareRoot] + 1;
            } else {
                dp[num] = 1;
            }
            maxStreak = max(maxStreak, dp[num]);
        }

        // Return -1 if the longest streak has only one element (no valid sequence), else return maxStreak
        return (maxStreak > 1) ? maxStreak : -1;
    }
    
    int longestSquareStreak(vector<int>& nums) {
        sort(nums.begin(),nums.end());

        // int n = nums.size();

        // vector<vector<int>> memo(n, vector<int>(n + 1, -1)); 
        // int ans = solveMem(0, -1, nums, memo);


        int ans=moreOptimize(nums);

        return ans;
    }
};




