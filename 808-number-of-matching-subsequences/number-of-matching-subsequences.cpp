class Solution {
public:
    int numMatchingSubseq(string s, vector<string>& words) {
        int ans=0;
        int n=s.size();
        unordered_map<string,bool>mp;
        for(auto &str:words)
        {
            if(mp.find(str)!=mp.end() && mp[str]==true)
            {
                ans++;
                continue;
            }
            int i=0; //s
            int j=0; //str
            while(i<n && j<str.size())
            {
                if(str[j]==s[i])
                {
                    i++;j++;
                }
                else{
                    i++;
                }
            }
            if(j==str.size()) 
            {
                mp[str]=true;
                ans++;
            }
            else mp[str]=false;

        }
        return ans;
    }
};