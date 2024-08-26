// class Solution {
// public:

//     int solve(vector<int>&nums,int target,int i,int sum)
//     {
//         if (i == nums.size()) {
//             return sum == target ? 1 : 0;
//         }
//         // Take the current number as positive
//         int op1 = solve(nums, target, i + 1, sum + nums[i]);
//         // Take the current number as negative
//         int op2 = solve(nums, target, i + 1, sum - nums[i]);

//         // No operation if nums[i] is zero (this is implicitly covered by op1 and op2)
//         return op1 + op2;
//     }
//     int findTargetSumWays(vector<int>& nums, int target) {
//         return solve(nums,target,0,0);
//     }
// };



//2.Memoziation

// Time Complexity:
// The time complexity is reduced to O(n×target), where n is the number of elements in nums and target is the range of possible sums.
// Space Complexity:
// The space complexity is O(n×target) for the memoization table, and O(n) for the recursion stack.
// class Solution {
// public:
//     // Memoization table to store the results of subproblems
//     unordered_map<string, int> memo;

//     int solve(vector<int>& nums, int target, int i, int sum) {
//         // Base case: If we have considered all elements
//         if (i == nums.size()) {
//             return sum == target ? 1 : 0;
//         }

//         // Create a unique key for memoization
//         string key = to_string(i) + "," + to_string(sum);
        
//         // If the subproblem has been solved before, return the stored result
//         if (memo.find(key) != memo.end()) {
//             return memo[key];
//         }

//         // Take the current number as positive
//         int op1 = solve(nums, target, i + 1, sum + nums[i]);
        
//         // Take the current number as negative
//         int op2 = solve(nums, target, i + 1, sum - nums[i]);

//         // Store the result in the memoization table
//         memo[key] = op1 + op2;

//         // Return the total count of ways
//         return memo[key];
//     }

//     int findTargetSumWays(vector<int>& nums, int target) {
//         return solve(nums, target, 0, 0);
//     }
// };



class Solution {
public:
    //2.Tabluation [Code of Perfect Sum Problem]

    int solveTab(vector<int>&arr, int n, int total){
        
        vector<vector<int>> dp(n+1, vector<int>(total + 1, 0));
        
        dp[n][0]=1;
    
        for(int i=n-1;i>=0;i--){
            for(int sum=0;sum<=total;sum++)
            {
                int notTake=dp[i+1][sum];
                int take=0;
                if(arr[i]<=sum)
                    take=dp[i+1][sum-arr[i]];
                
                dp[i][sum]=(notTake+take);
            }
            
        }
        return dp[0][total];
        
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        int n=nums.size();
        int sum = 0;
        for (int num : nums) {
            sum += num;
        }

        // If (sum + target) is odd or target is impossible, return 0
        if ((sum + target) % 2 != 0 || sum < target) return 0;

        if(sum + target<0) return 0; //e.g:- nums[100],and target=-100   (VERY IMP)
        int subsetSum = (sum + target) / 2;
        
        return solveTab(nums,n,subsetSum);
        
    }
};
