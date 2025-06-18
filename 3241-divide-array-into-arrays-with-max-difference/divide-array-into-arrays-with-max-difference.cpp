class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());

        vector<vector<int>> result;
        int n = nums.size();

        if (n % 3 != 0) return {}; // Optional sanity check

        for (int i = 0; i < n; i += 3) {
            int a = nums[i], b = nums[i + 1], c = nums[i + 2];
            if (c - a <= k) {
                result.push_back({a, b, c});
            } else {
                return {};
            }
        }

        return result;
    }
};


// class Solution {
// public:
//     vector<vector<int>> divideArray(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());

//         vector<vector<int>>ans;
//         int i=0;
//         int n=nums.size();
//         while(i<n)
//         {
//             int first=i;
//             int last=i+2;
//             if(abs(nums[first]-nums[last])<=k) 
//             {
//                 vector<int>temp;
//                 for(int j=i;j<=last;j++)
//                 {
//                     temp.push_back(nums[j]);
//                 }
//                 ans.push_back(temp);
//             }
//             else
//             {
//                 return {};
//             }
//             i=last+1;
//         }

//         return ans;

//     }
// };