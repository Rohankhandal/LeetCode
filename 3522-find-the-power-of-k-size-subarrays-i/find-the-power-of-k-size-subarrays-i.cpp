class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans;
        for (int i = 0; i <= n-k; i++) {
            bool isSorted = true;
            int maxi = nums[i];
            for (int j = i + 1; j < i + k; j++) {
                maxi = max(maxi, nums[j]);
                if (nums[j] <= nums[j - 1] || nums[j]!=nums[j-1]+1) {
                    isSorted = false;
                    break;
                }
            }
            if (isSorted) {
                ans.push_back(maxi);
            }
            else ans.push_back(-1);
        }
        return ans;
    }
};