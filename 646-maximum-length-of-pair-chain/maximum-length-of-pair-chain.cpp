class Solution {
public:
    int findLongestChain(vector<vector<int>>& pairs) {
        int n=pairs.size();
        sort(pairs.begin(),pairs.end());
        vector<int>dp(n,1);
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<i;j++)
            {
                int b=pairs[j][1];
                int c=pairs[i][0];
                if(b<c)
                {
                    dp[i]=max(dp[i],1+dp[j]);
                }
            }
        }
        int ans=0;
        //find max length
        for(int i=0;i<n;i++)
        {
            ans=max(ans,dp[i]);
        }
        return ans;
    }
};