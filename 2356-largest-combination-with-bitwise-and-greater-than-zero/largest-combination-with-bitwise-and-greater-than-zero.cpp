class Solution {
public:
    int largestCombination(vector<int>& candidates) {
        int ans=1;
        int n=candidates.size();
        vector<vector<int>>dp(n,vector<int>(32,0));

        for(int i=0;i<n;i++)
        {
            int num=candidates[i];
            for(int bit=31;bit>=0;bit--)
            {
                int digit=num&1;
                dp[i][bit]=digit;
                num>>=1;
            }
        }

        // for(int i=0;i<n;i++)
        // {
        //     cout<<candidates[i]<<" ";
        //     for(int bit=0;bit<32;bit++)
        //     {
        //         cout<<dp[i][bit];
        //     }
        //     cout<<endl;
        // }

        for(int i=0;i<32;i++)
        {
            int cnt=0;
            for(int j=0;j<n;j++)
            {
                if(dp[j][i]==1)
                    cnt++;
            }
            ans=max(ans,cnt);
        }

        return ans;



    }
};