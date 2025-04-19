class Solution {
public:
    long long countFairPairs(vector<int>& nums, int lower, int upper) {
        long long ans = 0;
        sort(nums.begin(), nums.end());
        int n = nums.size();
        
        for (int i = 0; i < n; ++i) {
            int l = lower - nums[i];
            int r = upper - nums[i];
            
            // Search for nums[j] such that i < j and:
            // lower <= nums[i] + nums[j] <= upper
            // => l <= nums[j] <= r

            // Only look in range after i to maintain i < j
            int left = lower_bound(nums.begin() + i + 1, nums.end(), l) - nums.begin();
            int right = upper_bound(nums.begin() + i + 1, nums.end(), r) - nums.begin();
            
            ans += (right - left);
        }
        return ans;
    }
};
