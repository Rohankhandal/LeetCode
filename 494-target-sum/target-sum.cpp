class Solution {
public:
    int solve(vector<int>&nums,int target,int i,int sum)
    {
        if (i == nums.size()) {
            return sum == target ? 1 : 0;
        }
        // Take the current number as positive
        int op1 = solve(nums, target, i + 1, sum + nums[i]);
        // Take the current number as negative
        int op2 = solve(nums, target, i + 1, sum - nums[i]);

        // No operation if nums[i] is zero (this is implicitly covered by op1 and op2)
        return op1 + op2;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
        return solve(nums,target,0,0);
    }
};