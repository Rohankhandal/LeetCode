class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>mp;
        set<int>s;
        for(auto &it:nums1)
        {
            mp[it]++;
        }
        //search on mp
        for(auto &it:nums2)
        {
            if(mp.find(it)!=mp.end())
            {
                s.insert(it);
            }
        }
        vector<int>ans;
        for(auto &it:s){
            ans.push_back(it);
        }
        return ans;
    }
};