class Solution {
public:
// bool cmp(pair<int,int>p1,pair<int,int>p2){
//     return p2.second>p1.second;
// }
    vector<int> topKFrequent(vector<int>& nums, int k) {
        vector<pair<int,int>>pairs;
        unordered_map<int,int>mp;
        for(int i=0;i<nums.size();i++) mp[nums[i]]++;
        for(auto x:mp){
            pairs.emplace_back(x);
        }
        sort(pairs.begin(),pairs.end(),[](const auto&a,const auto &b){return a.second>b.second;});
        vector<int>res;
        for(int i=0;i<k;i++){
            res.push_back(pairs[i].first);
        }
        return res;
    }
};