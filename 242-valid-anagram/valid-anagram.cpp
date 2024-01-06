class Solution {
public:
    bool isAnagram(string s, string t) {
        // int freqTable[256]={0};
        // for( int i=0; i<s.size(); i++)
        // {
        //     freqTable[s[i]]++;     //increment by 1 in freqtable along string s characters.
        // }
        // for( int i=0; i<t.size(); i++)
        // {
        //     freqTable[t[i]]--;      //decrement by 1 in freqtable along string s characters.
        // }
        // for( int i=0; i<256; i++)
        // {
        //    if(freqTable[i]!=0)
        //     return false;
        // }
        // return true;
        unordered_map<char,int>mp;
        for(int i=0;i<s.size();i++)
        {
            mp[s[i]]++;
        }
        //compare with t string 
        for(int i=0;i<t.size();i++)
        {
            mp[t[i]]--;
        }
        for(auto &it:mp)
        {
            if(it.second!=0)
            {
                return false;
            }
        }
        return true;
    }
};