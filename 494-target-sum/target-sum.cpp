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


class Solution {
public:
    // Memoization table to store the results of subproblems
    unordered_map<string, int> memo;

    int solve(vector<int>& nums, int target, int i, int sum) {
        // Base case: If we have considered all elements
        if (i == nums.size()) {
            return sum == target ? 1 : 0;
        }

        // Create a unique key for memoization
        string key = to_string(i) + "," + to_string(sum);
        
        // If the subproblem has been solved before, return the stored result
        if (memo.find(key) != memo.end()) {
            return memo[key];
        }

        // Take the current number as positive
        int op1 = solve(nums, target, i + 1, sum + nums[i]);
        
        // Take the current number as negative
        int op2 = solve(nums, target, i + 1, sum - nums[i]);

        // Store the result in the memoization table
        memo[key] = op1 + op2;

        // Return the total count of ways
        return memo[key];
    }

    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums, target, 0, 0);
    }
};
