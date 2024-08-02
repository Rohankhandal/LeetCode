class Solution {
public:
    int minSwaps(vector<int>& nums) {
        int n = nums.size();
        int one = 0;

        // Count total number of 1's
        for (int i = 0; i < n; i++) {
            if (nums[i] == 1) one++;
        }

        if (one == 0) return 0; // If there are no 1's, no swaps are needed

        // Initialize sliding window
        int cnt_one_in_window = 0;
        for (int i = 0; i < one; i++) {
            if (nums[i] == 1) cnt_one_in_window++;
        }

        // Initial minimum swaps
        int mini = one - cnt_one_in_window;

        // Slide the window over the array
        for (int i = 1; i < n; i++) {
            int end = (i + one - 1) % n;
            int start = (i - 1) % n;
            if (nums[start] == 1) cnt_one_in_window--;
            if (nums[end] == 1) cnt_one_in_window++;
            mini = min(mini, one - cnt_one_in_window);
        }

        return mini;
    }
};
