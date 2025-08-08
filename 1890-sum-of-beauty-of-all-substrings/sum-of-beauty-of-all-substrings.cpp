class Solution {
public:
    int beautySum(string s) {
        int n=s.size();
        int ans=0;
        for(int i=0;i<n;i++)
        {
            unordered_map<char,int>mp;
            
            for(int j=i;j<n;j++)
            {
                int maxi=INT_MIN;;
                int mini=INT_MAX;
                mp[s[j]]++;
                for(auto &it:mp)
                {
                    maxi=max(maxi,it.second);
                    mini=min(mini,it.second);
                }
                if(mp.size()>1)
                {
                    ans+=(maxi-mini);
                }

            }
        }
        return ans;
    }
};