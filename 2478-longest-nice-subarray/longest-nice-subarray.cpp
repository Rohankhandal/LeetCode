class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        int l=0;
        int r=0;
        int ans=0;
        int currSum=0;
        int currXor=0;
        while(r<n)
        {
            currSum+=nums[r];
            currXor^=nums[r];

            while(currSum!=currXor && l<r)
            {
                currSum-=nums[l];
                currXor^=nums[l];
                l++;
            }

            if(currSum==currXor)
                ans=max(ans,r-l+1);

            r++;
        }
        return ans;
    }
};