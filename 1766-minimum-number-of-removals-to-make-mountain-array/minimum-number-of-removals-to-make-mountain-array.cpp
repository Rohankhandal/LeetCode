class Solution {
public:
    int minimumMountainRemovals(vector<int>& nums) {
       int n = nums.size();
       
       // dp1[i] stores length of longest increasing subsequence ending at index i
       vector<int> dp1(n, 1); 
       // dp2[i] stores length of longest decreasing subsequence starting from index i
       vector<int> dp2(n, 1);

       // Fill dp1 for LIS ending at each index
       for (int i = 1; i < n; i++) {
           for (int j = 0; j < i; j++) {
               if (nums[j] < nums[i]) {
                   dp1[i] = max(dp1[i], 1 + dp1[j]);
               }
           }
       }

       // Fill dp2 for LIS starting from each index, working backwards
       for (int i = n - 2; i > 0; i--) {
           for (int j = n - 1; j > i; j--) {
               if (nums[j] < nums[i]) {
                   dp2[i] = max(dp2[i], 1 + dp2[j]);
               }
           }
       }
       
       int maxMountainSeq = 0;
       // Calculate the maximum valid mountain sequence length
       for (int i = 0; i < n; i++) {
           // A valid peak must have both an increasing and a decreasing sequence
           if (dp1[i] != 1 && dp2[i] != 1) {
               maxMountainSeq = max(dp1[i] + dp2[i] - 1, maxMountainSeq);
           }
       }

       // Minimum removals to get the mountain array
       return n - maxMountainSeq;
    }
};
