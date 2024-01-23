class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        vector<int>mp(256,0);
        int l=0,r=0;
        int n=s.size();
        int ans=0;
       while(r<n)
        {
            while(mp[s[r]]>0)
            {
                
                mp[s[l]]--;
                l++;
            }
            ans=max(ans,r-l+1);
            mp[s[r]]++;
            r++;
        }
        return ans;
    }
};