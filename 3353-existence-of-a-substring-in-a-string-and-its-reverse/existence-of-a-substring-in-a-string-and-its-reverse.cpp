class Solution {
public:
    bool isSubstringPresent(string s) {
        unordered_map<string,int>mp;
        for(int i=0;i<s.size()-1;i++)
        {
                string temp=s.substr(i,2);
                mp[temp]++;
        }
        reverse(s.begin(),s.end());
        for(auto &it:mp)
        {
            // cout<<it.first<<endl;
            if(s.find(it.first)!=string::npos) return true;
        }
        return false;
    }
};