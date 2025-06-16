class Solution {
public:
    int maximumDifference(vector<int>& nums) {
        int n=nums.size();
        int ans=-1;
        int mini=nums[0];
        for(int i=1;i<n;i++)
        {
            if(mini<nums[i])
                ans=max(ans,nums[i]-mini);
            mini=min(nums[i],mini);

        }
        return ans;
    }
};