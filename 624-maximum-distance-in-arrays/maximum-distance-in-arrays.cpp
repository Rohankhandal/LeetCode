class Solution {
public:
    int maxDistance(vector<vector<int>>& arr) {
        int n = arr.size();
        
        // Initialize with the first subarray
        int minStart = arr[0][0];
        int maxEnd = arr[0][arr[0].size() - 1];
        int ans = INT_MIN;

        for (int i = 1; i < n; i++) {
            int newStart = arr[i][0];
            int newEnd = arr[i][arr[i].size() - 1];
            
            // Calculate the maximum distance for this subarray with global extremes
            ans = max(ans, max(abs(newEnd - minStart), abs(maxEnd - newStart)));

            // Update global extremes if needed
            minStart = min(minStart, newStart);
            maxEnd = max(maxEnd, newEnd);
        }

        return ans;
    }
};
