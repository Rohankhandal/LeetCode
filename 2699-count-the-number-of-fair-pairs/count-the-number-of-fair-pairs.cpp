class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        // Sort the array to enable two-pointer/binary search approach
        sort(nums.begin(), nums.end());
        int n = nums.size();
        long long count = 0;
        
        // Iterate over each element as the first element in the pair
        for (int i = 0; i < n - 1; ++i) {
            // Find the range of indices for the second element in the pair
            long long  left = lower_bound(nums.begin() + i + 1, nums.end(), lower - nums[i]) - nums.begin();
            long long right = upper_bound(nums.begin() + i + 1, nums.end(), upper - nums[i]) - nums.begin();
            
            // Add the count of valid pairs (i, j) for this i
            if (left <= right) {
                count += (right - left);
            }
        }
        
        return count;
    }
};