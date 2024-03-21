class Solution {
public:
    string decodeMessage(string key, string message) {
        unordered_map<char,char>mp;
        char ch='a';
        for(int i=0;i<key.size();i++)
        {
            if(key[i]!=' '&&mp.find(key[i])==mp.end())
            {
                mp[key[i]]=ch;
                ch++;
            }
        }
        for(auto &it:message)
        {
            if(mp.find(it)!=mp.end())
            {
                it=mp[it];
            }
        }
        return message;
    }
};