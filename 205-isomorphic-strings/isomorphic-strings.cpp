class Solution {
public:
    bool isIsomorphic(string s, string t) {
        unordered_map<char,char>forward;
        unordered_map<char,char>reverse;

        for(int i=0;i<s.size();i++)
        {
            if(forward.find(s[i])!=forward.end())
            {
                if(forward[s[i]]!=t[i]) return false;
            }
            if(reverse.find(t[i])!=reverse.end())
            {
                if(reverse[t[i]]!=s[i]) return false;
            }

            forward[s[i]]=t[i];
            reverse[t[i]]=s[i];

        }
        return true;
    }
};