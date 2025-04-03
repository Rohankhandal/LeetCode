class Solution {
public:
    long long maximumTripletValue(vector<int>& nums) {
        long long ans=0;
        int maxI=0;
        int maxDiff=0;
        int n=nums.size();
        for(int k=0;k<n;k++)
        {
            ans=max(ans,(long long )maxDiff*nums[k]);

            maxI=max(nums[k],maxI);
            maxDiff=max(maxDiff,(maxI-nums[k]));
        }

        return ans;
    }
};