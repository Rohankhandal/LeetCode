class Solution {
public:
    char kthCharacter(int k) {
        string s="a";
        while(s.size()<k)
        {
            int sz=s.size();
            for(int i=0;i<sz;i++){
                s+=((s[i]-'a'+1)%26)+'a';
            }
        }
        cout<<s<<endl;
        return s[k-1];
    }
};