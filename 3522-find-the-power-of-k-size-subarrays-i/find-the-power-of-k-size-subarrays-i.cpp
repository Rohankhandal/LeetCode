
class Solution {
public:
    vector<int> resultsArray(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> ans(n-k+1,-1);
        int consecutiveCnt=0;
        for(int i=0;i<n;i++)
        {
            if(i>0 && nums[i]==nums[i-1]+1) consecutiveCnt++;
            else consecutiveCnt=1;

            if(consecutiveCnt>=k) ans[i-k+1]=nums[i];
        }
        return ans;
    }
};

// T.C:-O(N^2)
// class Solution {
// public:
//     vector<int> resultsArray(vector<int>& nums, int k) {
//         int n = nums.size();
//         vector<int> ans;
//         for (int i = 0; i <= n-k; i++) {
//             bool isSorted = true;
//             int maxi = nums[i];
//             for (int j = i + 1; j < i + k; j++) {
//                 maxi = max(maxi, nums[j]);
//                 if (nums[j] <= nums[j - 1] || nums[j]!=nums[j-1]+1) {
//                     isSorted = false;
//                     break;
//                 }
//             }
//             if (isSorted) {
//                 ans.push_back(maxi);
//             }
//             else ans.push_back(-1);
//         }
//         return ans;
//     }
// };