class Solution {
public:
    int numSubarrayProductLessThanK(vector<int>& nums, int k) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            long long prod=1;
            for(int j=i;j<n;j++)
            {
                prod=prod*nums[j];
                if(prod<k)
                {
                    ans++;
                }
                else
                {
                    break;
                }
            }
        }
        return ans;
    }
};