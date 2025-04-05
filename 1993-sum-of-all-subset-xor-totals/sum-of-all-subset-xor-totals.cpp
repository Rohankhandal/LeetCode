class Solution {
public:
    int subsetXORSum(vector<int>& nums) {
        int n=nums.size();
        int ans=0;
        int total=pow(2,n);

        for(int i=0;i<total;i++)
        {
            int sum=0;
            for(int j=0;j<n;j++)
            {
                if(i&(1<<j))
                {
                    sum^=nums[j];
                }
            }
            ans+=sum;
        }
        return ans;
    }
};