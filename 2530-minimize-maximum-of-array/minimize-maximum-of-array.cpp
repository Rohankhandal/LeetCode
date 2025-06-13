class Solution {
public:
    bool isPossible(vector<int> nums, int tar) {
        long long sum = 0;
        for (int i = 0; i < nums.size(); ++i) {
            sum += nums[i];
            long long maxAllowed = 1LL * (i + 1) * tar;
            if (sum > maxAllowed) return false;
        }
        return true;
    }

    int minimizeArrayValue(vector<int>& nums) {
        int l = 0, r = *max_element(nums.begin(), nums.end());
        int ans = r;
        
        while (l <= r) {
            int mid = (l + r) / 2;
            if (isPossible(nums, mid)) {
                ans = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }

        return ans;
    }
};
