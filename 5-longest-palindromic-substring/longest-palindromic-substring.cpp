class Solution {
public:
    int t[1001][1001];
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=1;  //every letter is a substring and palindrome
        //all substrings of length 1 palindrome
        int startingIndex=0;
        memset(t,0,sizeof(t));
        for(int L=1;L<=n;L++)
        {
            for(int i=0;i+L-1<n;i++)
            {
                int j=i+L-1;

                if(i==j)  //1 length string
                {
                    t[i][j]=1;
                }
                else if(s[i]==s[j] && L==2) //2 length string
                {
                    t[i][j]=1;
                    maxLen=2;
                    startingIndex=i;
                }
                else if(s[i]==s[j] && t[i+1][j-1]==true){
                    t[i][j]=1;
                    if(maxLen<(j-i+1))
                    {
                        maxLen=(j-i+1);
                        startingIndex=i;
                    }
                }
                else
                {
                    t[i][j]=0;
                }
            }
        }
        return s.substr(startingIndex,maxLen);
    }
}; 