class Solution {
public:
    string invert(string s)
    {
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='1') s[i]='0';
            else s[i]='1';
        }
        return s;
    }
    string solve(int n)
    {
        if(n==1) return "0";

        string temp=solve(n-1);
        string invertTemp=invert(temp);
        reverse(invertTemp.begin(),invertTemp.end());
        string str=temp+"1"+invertTemp;

        return str;
    }
    char findKthBit(int n, int k) {
        string s=solve(n);
        return s[k-1];
    }
};