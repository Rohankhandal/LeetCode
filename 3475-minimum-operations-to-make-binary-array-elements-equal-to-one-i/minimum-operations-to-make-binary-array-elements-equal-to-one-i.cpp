class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size();
        vector<int>flip(n,0);
        int cnt=0;
        for(int i=0;i<=n-3;i++)
        {
            if((flip[i]+nums[i])%2==0)
            {
                for(int j=i;j<i+3&&j<n;j++)
                {
                    flip[j]++;
                }
                cnt++;
            }
        }

        for(int i=0;i<n;i++)
        {
            if((flip[i]+nums[i])%2==0) return -1;
        }
        return cnt;
    }
};