class Solution {
public:
    int M=1e9+7;
    int rangeSum(vector<int>& nums, int n, int left, int right) {
        // int n=nums.size();
        vector<int>arr;

        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                int sum=0;
                if(i<=j)
                {
                    for(int k=i;k<=j;k++)
                    {
                        sum+=nums[k]%M;
                    }
                    arr.push_back(sum);
                }
                
            }
        }
        sort(arr.begin(),arr.end());
        int ans=0;
        for(int i=left;i<=right;i++)
        {
            ans=(ans%M+arr[i-1]%M)%M;
        }
        return ans;
    }
};