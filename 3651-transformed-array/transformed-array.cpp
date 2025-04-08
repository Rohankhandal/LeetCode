class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n=nums.size();
        vector<int>ans(n,0);
        // cout<<(-7%2)<<endl;
        for(int i=0;i<n;i++)
        {
            if(nums[i]<0)
            {
                ans[i]=nums[((i+nums[i])%n+n)%n];
            }
            else if(nums[i]>0)
            {
                ans[i]=nums[(i+nums[i])%n];
            }   
            else
            {
                ans[i]=0;
            }
        }
        return ans;
    }
};