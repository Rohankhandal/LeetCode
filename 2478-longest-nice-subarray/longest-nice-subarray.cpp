class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n=nums.size();
        int res=0;
        int l=0;
        int r=0;
        int ans=0;
        while(r<n)
        {
            while((nums[r]&res)!=0)
            {
                res^=nums[l];
                l++;
            }

            ans=max(ans,r-l+1);
            res|=nums[r];
            r++;
        }
        return ans;
    }
};