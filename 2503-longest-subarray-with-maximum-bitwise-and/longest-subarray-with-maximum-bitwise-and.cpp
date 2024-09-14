class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        int maxVal = *max_element(nums.begin(), nums.end());
          int maxLength = 0, currentLength = 0;

        // Traverse the array to find the length of the longest subarray with the maximum value
        for (int i = 0; i < nums.size(); ++i) {
            if (nums[i] == maxVal) {
                currentLength++;
                maxLength = max(maxLength, currentLength);
            } else {
                currentLength = 0;
            }
        }

        return maxLength;
    }
};