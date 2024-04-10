class Solution {
public:
    int partitionString(string s) {
        unordered_map<char,int>mp;
        int n=s.size();
        int i=0,j=0;
        int cnt=1;
        while(j<n)
        {
            mp[s[j]]++;
            bool flag=true;
            if(mp[s[j]]>=2)
            {
                cnt++;
                mp.clear();
                mp[s[j]]++;
            }
            j++;

        }
        return cnt;
    }
};