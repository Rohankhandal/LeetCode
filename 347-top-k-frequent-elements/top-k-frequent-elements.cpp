class Solution {
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<int>ans;
        unordered_map<int,int>mp;
        for(auto &num:nums)
        {
            mp[num]++;
        }
        auto myComp=[&mp](int &a,int &b)
        {
            if(mp[a]==mp[b]) return a<b;
            return mp[a]>mp[b];
        };
        vector<int>temp;
        for(auto &it:mp)
        {
            temp.push_back(it.first);
        }
        sort(temp.begin(),temp.end(),myComp);
        for(int i=0;i<k;i++)
        {
            ans.push_back(temp[i]);
        }
        return ans;
    }
};