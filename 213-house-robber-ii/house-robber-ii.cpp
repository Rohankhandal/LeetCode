class Solution {
public:
    int space(vector<int>&nums)
     {
        int n=nums.size();
        int prev2=0,prev1=0;

        for(int i=n-1;i>=0;i--)
        {
            int take=nums[i]+prev2;
            int notake=0+prev1;

            int curr=max(take,notake);
            prev2=prev1;
            prev1=curr;
        }
        return prev1;

     }
    int rob(vector<int>& nums) {
        if(nums.size()==1) return nums[0];
        vector<int>nums1(nums.begin(),nums.end()-1);
        int val1=space(nums1);
         vector<int>nums2(nums.begin()+1,nums.end());
        int val2=space(nums2);
        return max(val1,val2);

    }
};