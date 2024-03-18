class Solution {
public:
     bool static cmp(pair<int,int>&p1,pair<int,int>&p2)
    {
        return p1.second>p2.second;
    }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        int n=nums.size();
        vector<pair<int,int>>v;
        unordered_map<int,int>mp;
        vector<int>ans;
        for(auto &it:nums) mp[it]++;
        for(auto &x:mp)
        {
            v.emplace_back(x);
        }
        sort(v.begin(),v.end(),cmp);
        for(auto &it:v)
        {
            if(k==0) break;
            ans.push_back(it.first);
            k--;
        }
        return ans;
    }
};