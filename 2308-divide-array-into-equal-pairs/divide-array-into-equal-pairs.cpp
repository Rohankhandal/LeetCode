class Solution {
public:
    bool divideArray(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &num:nums)
        {
            mp[num]++;

        }
        for(auto &it:mp)
        {
            if(it.second&1) return false;
        }
        return true;
    }
};