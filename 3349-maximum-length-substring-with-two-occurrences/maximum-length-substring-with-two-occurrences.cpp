class Solution {
public:
    int maximumLengthSubstring(string s) {
        unordered_map<char,int>mp;
        int maxOcc=0;
        int l=0,r=0;
        int maxi=0;
        while(r<s.size())
        {
            while(l<=r && mp[s[r]]>=2)
            {
                mp[s[l++]]--;
            }
            maxi=r-l+1;
            maxOcc=max(maxi,maxOcc);
            mp[s[r]]++;
            r++;
        }
        return maxOcc;
    }
};