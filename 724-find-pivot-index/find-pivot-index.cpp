class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int sum = 0;
        int leftSum = 0;

        // Calculate the total sum of the array
        for (int i = 0; i < nums.size(); i++) {
            sum += nums[i];
        }

        // Iterate through the array to find the pivot index
        for (int i = 0; i < nums.size(); i++) {
            sum = sum - nums[i];

            // Check if the current index is a pivot index
            if (leftSum == sum) {
                return i;
            }

            leftSum += nums[i];
        }

        // If no pivot index is found, return -1
        return -1;
    }
};