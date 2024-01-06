class Solution {
public:
    int missingNumber(vector<int>& nums) {
       int n = nums.size();
    int res = n;
    for(int i=0;i<n;i++){
        res^=i;
        res^=nums[i];
    }
    return res;
    }
};



//first method
//  int eSum=0;
//         int sum=0;
//         for(int i=0;i<nums.size();i++){
//             eSum+=nums[i];

//         }
//         for(int i=0;i<=nums.size();i++)
//         {
//             sum+=i;
//         }
//         int ans=sum-eSum;
//         return ans;