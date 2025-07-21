class Solution {
public:
    string makeFancyString(string s) {
        string ans="";
        int n=s.size();
        for(int i=0;i<n-2;i++)
        {
           
                if(s[i]==s[i+1] && s[i]==s[i+2])
                {
                    continue;
                }
                else
                {
                    ans+=s[i];
                }

        }
        if(n-2>=0) ans+=s[n-2]; if(n-1>=0)ans+=s[n-1];
        return ans;
    }
};