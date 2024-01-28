class Solution {
public:
    int findMiddleIndex(vector<int>& nums) {
        int n=nums.size(),sum=0,lefts=0;
        for(auto i:nums)
        sum+=i;
        for(int i=0;i<n;i++)
        {
            if(lefts==sum-nums[i])
            return i;
            lefts+=nums[i];
            sum-=nums[i];
        }
        return -1;
    }
};
// Time complexity:-O(N)
// class Solution {
// public:
//     int findMiddleIndex(vector<int>& nums) {
//         int preSum=0;
//         int index=-1;
//         int i;
//         for( i=0;i<nums.size()-1;i++)
//         {
//             int endSum=0;
//             for(int j=i+1;j<nums.size();j++)
//             {
//                 endSum+=nums[j];
//             }
//             if(preSum==endSum)
//             {
//                 index=i;
//                 break;
//             }
//             preSum+=nums[i];
//         }
//         if(i==nums.size()-1 && preSum==0)
//         {
//             index=i;
//         }
//         return index;
//     }
// };