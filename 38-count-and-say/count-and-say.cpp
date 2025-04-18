class Solution {
public:
    string solve(int n)
    {
        if(n==1) return "1";

        string str=solve(n-1);
        string ans="";
        int i=0;
        while(i<str.size())
        {
            char ch=str[i];
            int count=0;
            while(i<str.size()&&str[i]==ch){
                count++;
                i++;
            }
            ans+=to_string(count) + ch;
        }
        cout<<ans<<endl;
        return ans;
    }
    string countAndSay(int n) {
        return solve(n);
    }
};