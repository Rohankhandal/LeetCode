class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        unordered_map<int,int>mp;
        for(auto &it:nums)
        {
            mp[it]++;
        }
        for(int i=1;i<INT_MAX;i++){
            if(mp.find(i)==mp.end())
                return i;
        }
        return 0;
    }
};