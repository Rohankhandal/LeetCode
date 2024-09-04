class Solution {
public:
    int t[1001][1001];
    bool isPalindrome(string&s,int i,int j)
    {
        if(i>j) return true;

        if(t[i][j]!=-1) return t[i][j];
        
        if(s[i]==s[j]){
            return t[i][j]=isPalindrome(s,i+1,j-1);
        }
        return t[i][j]=false;
    }
    string longestPalindrome(string s) {
        int n=s.size();
        int maxLen=INT_MIN;
        int startIndex=0;
        memset(t,-1,sizeof(t));
        
        for(int i=0;i<n;i++)
        {
            for(int j=i;j<n;j++)
            {
                if(isPalindrome(s,i,j))
                {
                    // cout<<s.substr(i,(j-i+1))<<endl;;
                    if(maxLen<(j-i+1))
                    {
                        maxLen=(j-i+1);
                        startIndex=i;
                    }
                }
            }
        }
        return s.substr(startIndex,maxLen);
    }
}; 