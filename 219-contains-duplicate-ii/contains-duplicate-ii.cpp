class Solution {
public:
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
       int n=nums.size();
        unordered_map<int,int>mp;
        for(int i=0;i<n;i++)
        {
           int val=nums[i];
           if(mp.find(val)!=mp.end())
           {
               if(abs(i-mp[val])<=k)
                return true;
           }
           mp[val]=i;
        }
        return false;
    }
};