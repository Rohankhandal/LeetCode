class Solution {
public:
    long long findMaximumScore(vector<int>& nums) {
        int n=nums.size();

        long long  i=0;
        long long prev=nums[0];
        long long ans=0;
        for(int idx=1;idx<n;idx++)
        {
            if(idx==n-1)
            {
                ans+=(idx-i)*prev;
                break;
            }
            if(nums[idx]>nums[i])
            {
                ans+=(idx-i)*prev;
                prev=nums[idx];
                i=idx;
            }
        }
        return ans;
    }
};