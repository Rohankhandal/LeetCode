class Solution {
public:
    int countPalindromicSubsequence(string s) {
        int n=s.size();
        map<char,pair<int,int>>mp;
        for(char ch='a';ch<='z';ch++)
        {
            mp[ch]={-1,-1};
        }

        for(int i=0;i<n;i++)
        {
            if(mp[s[i]].first==-1) mp[s[i]].first=i;
        }
        for(int i=n-1;i>=0;i--)
        {
            if(mp[s[i]].second==-1) mp[s[i]].second=i;
        }

        int ans=0;
        for(auto &it:mp)
        {
            char ch=it.first;
            int start=it.second.first;
            int end=it.second.second;

            map<char,int>mp;
            for(int i=start+1;i<end;i++)
            {
                mp[s[i]]++;
            }
            ans+=mp.size();
        }
        return ans;
    }
};