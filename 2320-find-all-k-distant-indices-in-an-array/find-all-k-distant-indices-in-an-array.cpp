class Solution {
public:
    vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
        int n = nums.size();
        vector<bool> valid(n, false);
        vector<int> ans;

        for (int i = 0; i < n; ++i) {
            if (nums[i] == key) {
                int start = max(0, i - k);
                int end = min(n - 1, i + k);
                for (int j = start; j <= end; ++j) {
                    valid[j] = true;
                }
            }
        }

        for (int i = 0; i < n; ++i) {
            if (valid[i]) {
                ans.push_back(i);
            }
        }

        return ans;
    }
};



// class Solution {
// public:
//     vector<int> findKDistantIndices(vector<int>& nums, int key, int k) {
//         vector<int>ans;
//         int n=nums.size();
//         for(int i=0;i<n;i++)
//         {
//             int cnt=0;
//             for(int j=0;j<n;j++)
//             {
//                 // if(i==j) continue;
//                 if(abs(i-j)<=k && nums[j]==key)
//                 {
//                     cnt++;
//                 }
//             }

//             if(cnt>=1) ans.push_back(i);
//         }
//         return ans;

//     }
// };