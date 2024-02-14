class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> ans(n, 0);
        int pos = 0, neg = 1;
        for(int i = 0; i < n; ++i) {
            if(nums[i] >= 0) {
                ans[pos] = nums[i];
                pos += 2;
            }
            else {
                ans[neg] = nums[i];
                neg += 2;
            }
        }
        return ans;
    }
};
// Not Fully Optimized
// class Solution {
// public:
//     vector<int> rearrangeArray(vector<int>& nums) {
//         int n=nums.size();
//         int midSize=n/2;
//         vector<int>pos;
//         vector<int>neg;
//         for(auto &it:nums)
//         {
//             if(it<0)
//             {
//                 neg.push_back(it);
//             }
//             else{
//                 pos.push_back(it);
//             }

//         }
//         //now reorder the value using both arrays 
//         int posIndex=0;
//         int negIndex=0;
//         for(int i=0;i<n;i++)
//         {
//             if(i%2==0)
//             {
//              nums[i]=pos[posIndex++];   
//             }
//             else
//             {
//                 nums[i]=neg[negIndex++];
//             }

//         }
//         return nums;
//     }
// };