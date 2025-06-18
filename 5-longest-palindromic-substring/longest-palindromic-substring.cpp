class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        vector<vector<bool>> t(n, vector<bool>(n, false));
        int maxL = 1;
        int start = 0;
        
        for(int i = 0; i<n; i++)
            t[i][i] = true;
      
        
        for(int L = 2; L<=n; L++) {
            for(int i = 0; i<n-L+1; i++) {
                int j = i + L - 1;
                
                if(s[i] == s[j] && (t[i+1][j-1] || L == 2)) {
                    t[i][j] = true;
                    if(L > maxL) {
                        maxL = L;
                        start = i;
                    }
                }
            }
        }
        
        return s.substr(start, maxL);
    }
};

// class Solution {
// public:
//     string longestPalindrome(string s) {
//         int n=s.size();
//         vector<vector<bool>>dp(n,vector<bool>(n,false));
//         for(int L=1;L<=n;L++)
//         {
//             for(int i=0;i+L-1<n;i++){
//                 int j=i+L-1;

//                 if(i==j)
//                 {
//                     dp[i][j]=true;
//                 }
//                 else if(i+1==j)
//                 {
//                     dp[i][j]=(s[i]==s[j]);
//                 }
//                 else
//                 {
//                     dp[i][j]=(s[i]==s[j])&&dp[i+1][j-1];
//                 }
//             }
//         }
        
//         int idx=0;
//         int maxLen=0;
        
//         for(int i=0;i<n;i++)
//         {
//             for(int L=0;L<n;L++)
//             {
//                 if(dp[i][L])
//                 {
//                     int len=L-i+1;
//                     if(len>maxLen)
//                     {
//                         maxLen=len;
//                         idx=i;
//                     }
//                 }
//                 // cout<<dp[i][L]<<" ";
//             }
//             // cout<<endl;
//         }
//         // cout<<maxLen<<" "<<idx<<endl;
//         return s.substr(idx,maxLen);
//     }
// };