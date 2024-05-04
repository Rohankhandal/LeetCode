class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int l=0,r=0,n=nums.size();
        int ans=0;
        int mul=1;
        if(k==0) return 0;
        while(r<n)
        {
            mul*=nums[r];
            while(l<=r && mul>=k)
            {
                mul/=nums[l];
                l++;
            }
            ans+=(r-l+1);
            r++;
        }
        return ans;
    }
};