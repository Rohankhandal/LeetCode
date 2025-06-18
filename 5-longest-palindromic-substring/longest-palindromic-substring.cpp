class Solution {
public:
    string longestPalindrome(string s) {
        int n=s.size();
        vector<vector<bool>>dp(n,vector<bool>(n,false));
        for(int L=1;L<=n;L++)
        {
            for(int i=0;i+L-1<n;i++){
                int j=i+L-1;

                if(i==j)
                {
                    dp[i][j]=true;
                }
                else if(i+1==j)
                {
                    dp[i][j]=(s[i]==s[j]);
                }
                else
                {
                    dp[i][j]=(s[i]==s[j])&&dp[i+1][j-1];
                }
            }
        }
        
        int idx=0;
        int maxLen=0;
        
        for(int i=0;i<n;i++)
        {
            for(int L=0;L<n;L++)
            {
                if(dp[i][L])
                {
                    int len=L-i+1;
                    if(len>maxLen)
                    {
                        maxLen=len;
                        idx=i;
                    }
                }
                // cout<<dp[i][L]<<" ";
            }
            // cout<<endl;
        }
        // cout<<maxLen<<" "<<idx<<endl;
        return s.substr(idx,maxLen);
    }
};