class Solution {
public:
    int findLengthOfShortestSubarray(vector<int>& arr) {
        int n = arr.size();
        
        // Find the first decreasing element from left
        int left = 0;
        while (left + 1 < n && arr[left] <= arr[left + 1]) {
            left++;
        }
        
        // If array is already sorted, return 0
        if (left == n - 1) return 0;
        
        // Find the first increasing element from right
        int right = n - 1;
        while (right > 0 && arr[right - 1] <= arr[right]) {
            right--;
        }
        
        // Initial result: minimum of removing left part or right part
        int result = min(n - left - 1, right);
        
        // Try to join left sorted part with right sorted part
        int i = 0, j = right;
        while (i <= left && j < n) {
            if (arr[i] <= arr[j]) {
                // If we can join at this point, calculate length to remove
                result = min(result, j - i - 1);
                i++;
            } else {
                j++;
            }
        }
        
        return result;
    }
};