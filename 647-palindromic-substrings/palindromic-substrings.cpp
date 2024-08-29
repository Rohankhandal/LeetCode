class Solution {
public:

    int countSubstrings(string s) {
       int n=s.size();
       vector<vector<bool>>dp(n,vector<bool>(n,false));
        //dp[i][j]==true  : s[i:j] is a substring where i and j are inclusive indices

        int count=0;
      for(int L=1;L<=n;L++)
      {
         for(int i=0;i+L<=n;i++)
         {
            int j=i+L-1;

            if(i==j)  //1 length string 
            {
                dp[i][j]=true;
            }
            else if(i+1==j)  //2 length string 
            { 
                dp[i][j]=(s[i]==s[j]);
            }
            else
            {
                dp[i][j]=((s[i]==s[j]) && dp[i+1][j-1]==true);
            }

            if(dp[i][j])
            {
                count++;
            }
         }
      }
      return count;
    }
};

//T.C:-O(N^2)
// class Solution {
// public:
//     int expandAroundIndex(string s, int left, int right)
//     {
//         int count=0;
//         //jab tak match karega , tab tak count increment kardo and i piche and j aage kardo
//         while(left>=0 && right< s.length() && s[left]==s[right])
//         {
//             count++;
//             left--;
//             right++;
//         }
//         return count;
//     }
//     int countSubstrings(string s) {
//        int count=0;
//        int n=s.length();
//        for(int center=0;center<n; center++)
//        {
//            //odd
//            int oddKaAns = expandAroundIndex(s,center,center);
//            count=count+oddKaAns;
//            //even
//            int evenKaAns = expandAroundIndex(s,center,center+1);
//            count=count+evenKaAns;
//        }
//        return count;
//     }
// };