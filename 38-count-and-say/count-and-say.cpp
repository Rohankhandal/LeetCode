class Solution {
public:
    string countAndSay(int n) {
        if(n==1) return "1";

        string s=countAndSay(n-1);

       
        string ans="";
        int i=0;
        while(i<s.size())
        {
            char ch=s[i];
            int cnt=0;
            while(ch==s[i])
            {
                i++;
                cnt++;
            }

            ans=ans+(char)(cnt+'0')+ch;
        }

        return ans;
    }
};