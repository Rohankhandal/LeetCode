class Solution {
public:
    int findLHS(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &it:nums)
        {
            mp[it]++;
        }

        int ans=0;
        for(auto &it:mp)
        {
            if(mp.find(it.first+1)!=mp.end())
            {
                ans=max(ans,mp[it.first]+mp[it.first+1]);
            }
        }
        return ans;
    }
};