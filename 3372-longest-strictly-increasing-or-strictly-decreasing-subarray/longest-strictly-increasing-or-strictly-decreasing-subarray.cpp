class Solution {
public:
    int longestMonotonicSubarray(vector<int>& nums) {
        int n=nums.size();
        int ans=1;
        int inclen=1;
        int declen=1;
        for(int i=1;i<n;i++){
            if(nums[i]>nums[i-1])
            {
                inclen++;
                ans=max(ans,inclen);
            }
            else
            {
                inclen=1;
            }

            if(nums[i]<nums[i-1])
            {
                declen++;
                ans=max(ans,declen);
            }
            else
            {
                declen=1;
            }
        }
        return ans;
    }
};