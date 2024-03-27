class Solution {
public:
    char findTheDifference(string s, string t) {
        if(s.size()==0) return t[0];
        
        int ch=s[0]-'a';
        for(int i=1;i<s.size();i++)
        {
           ch=ch^(s[i]-'a'); 
        }
        cout<<ch;
        for(auto &it:t)
        {
           ch=ch^(it-'a'); 
        }
        return ch+'a';
    }
};