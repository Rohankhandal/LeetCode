class Solution {
public:
    int minKBitFlips(vector<int>& nums, int k) {
        int n = nums.size(); // Length of the input array
        int flip = 0;        // Number of current flips
        int ans = 0;         // Number of flips needed to convert the array to all 1s
        vector<bool> flipArray(n, false); // Track where the flips happen
        
        for (int i = 0; i < n; ++i) {
            // If the flip effect of position (i - k) has ended, decrement the flip counter
            if (i >= k && flipArray[i - k]) {
                flip--;
            }
            
            // Check if the current element needs to be flipped
            if ((flip + nums[i]) % 2 == 0) {
                // If flipping the subarray starting at i goes out of bounds, return -1
                if (i + k > n) return -1;
                
                // Mark the current position as flipped
                flipArray[i] = true;
                flip++;
                ans++;
            }
            
            // Update the current element in nums to reflect its final state
            nums[i] = (flip + nums[i]) % 2;
        }
        
        // Check if all elements in the array are 1 after processing
        for (int i = 0; i < n; ++i) {
            if (nums[i] == 0) return -1;
        }
        
        return ans;
    }
};
