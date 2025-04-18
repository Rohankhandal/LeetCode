class Solution {
public:
    string f(int n)
    {
        if(n==1) return "1";
        string s=f(n-1);

        string ans="";
        int i=0;
        while(i<s.size())
        {
            char ch=s[i];
            int cnt=0;
            while(i<s.size() && ch==s[i])
            {
                i++;
                cnt++;
            }
            ans=ans+to_string(cnt)+ch;
        }
        return ans;
    }
    string countAndSay(int n) {
        return f(n);
    }
};