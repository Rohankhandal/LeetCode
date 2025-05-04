class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        map<vector<int>,int>mp;
        for(auto &d:dominoes)
        {
            sort(d.begin(),d.end());
            mp[d]++;
        }
        int ans=0;
        for(auto &it:mp)
        {
            int val=it.second;
            if(val>1)
            {
                ans+=(val*(val-1))/2;
            }
        }
        return ans;
    }
};