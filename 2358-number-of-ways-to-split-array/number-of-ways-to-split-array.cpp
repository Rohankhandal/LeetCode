class Solution {
public:
    int waysToSplitArray(vector<int>& nums) {
        int n=nums.size();
        vector<long long>preSum(n,0);
        for(int i=0;i<n;i++) preSum[i]=nums[i];
        for(int i=1;i<n;i++)
        {
            preSum[i]+=preSum[i-1];
        }   
        int ans=0;
        for(int i=0;i<n-1;i++)
        {
            long long  left=preSum[i];
             long long  right=preSum[n-1]-preSum[i];
            if(left>=right) ans++;
        }
        return ans;
    }
};