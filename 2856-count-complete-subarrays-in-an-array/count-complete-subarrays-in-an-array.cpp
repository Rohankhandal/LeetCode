class Solution {
public:
    int countCompleteSubarrays(vector<int>& nums, int left = 0, int res = 0) {
        int k = unordered_set<int>(nums.begin(),nums.end()).size();
        unordered_map<int, int> mpp;

        for (int i = 0; i < nums.size(); ++i) {
            mpp[nums[i]]++;
            while (mpp.size() == k) {
                res += nums.size() - i;  
                mpp[nums[left]]--;
                if (mpp[nums[left]] == 0) mpp.erase(nums[left]);
                left++;
            }
        }
        return res;
    }
};


// class Solution {
// public:
//     int countCompleteSubarrays(vector<int>& nums) {
//         int n = nums.size();
//         unordered_set<int> freq;
        
//         for(int i = 0; i < n; i++) {  //to count distinct ele
//             freq.insert(nums[i]);
//         }
        
//         int distinct = freq.size();
//         int ans = 0;
    
//         for (int i = 0; i < n; i++) {
//             unordered_set<int> temp;

//             for(int j = i; j < n; j++) {
//                 temp.insert(nums[j]);
//                 if (temp.size() == distinct) {
//                     ans++;
//                 }
//             }
//         }
    
//     return ans;   
//     }
// };