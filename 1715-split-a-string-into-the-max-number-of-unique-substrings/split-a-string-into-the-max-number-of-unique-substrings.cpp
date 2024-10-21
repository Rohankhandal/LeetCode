class Solution {
public:
    void solve(string s,int i,unordered_map<string,int>&mp,int &ans)
    {
        if(i==s.size())
        {
            int sz=mp.size();
            ans=max(ans,sz);
            cout<<ans<<endl;
            return ;
        }
        for(int idx=i;idx<s.size();idx++)
        {
            string temp = s.substr(i, idx - i + 1);  // Get the substring from i to idx
            // cout<<idx<<" "<<temp<<endl;
            if(mp.find(temp)==mp.end())
            {
                mp[temp]++;
                solve(s,idx+1,mp,ans);
                 mp.erase(temp);  // Backtrack by removing the substring from the map
            }
        }
    }
    int maxUniqueSplit(string s) {
        unordered_map<string,int>mp;
        int n=s.size();
        int ans=0;
        // vector<string>&temp;
        solve(s,0,mp,ans);
        return ans;
    }
};