class Solution {
public:
    string reversePrefix(string s, char ch) {
        int index=s.find(ch);
        if(index==string::npos) return s;

        string ans=s.substr(0,index+1);
        reverse(ans.begin(),ans.end());
        ans+=(s.substr(index+1));
        return ans;
    }
};