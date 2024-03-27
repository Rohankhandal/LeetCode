class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int n=nums.size();
        int i=0,j=0;
        int mul=1;
        int ans=0;

        while(j<n)
        {
            mul=mul*nums[j];
            while(i<=j && mul>=k )
            {
                mul/=nums[i];
                i++;
            }
            ans+=(j-i+1);
            j++;
        }
        return ans;
    }
};