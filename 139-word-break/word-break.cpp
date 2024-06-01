class Solution {
public:
    int t[301];
    bool solve(string s,int i,unordered_map<string,int>&mp)
    {
        if(i>=s.size())
        {
            return true;
        }
        // if(mp.find(s)!=mp.end()) return t[i]=true;
        if(t[i]!=-1) return t[i];
        for(int l=1;l<=s.size();l++)
        {
            string temp=s.substr(i,l);
            if(mp.find(temp)!=mp.end() && solve(s,i+l,mp))
            {
                return t[i]=true;
            }
        }
        return t[i]=false;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        unordered_map<string,int>mp;
        memset(t,-1,sizeof(t));
        for(auto &str:wordDict)
        {
            mp[str]++;
        }
        return solve(s,0,mp);
    }
};