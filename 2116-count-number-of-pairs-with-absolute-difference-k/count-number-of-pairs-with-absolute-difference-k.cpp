class Solution {
public:
    int countKDifference(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int count=0;
        for(auto it:nums)
        {
            int sub=it-k;
            int sum=it+k;
            if(mp.find(sub)!=mp.end())
            {
                count+=mp[sub];
            }
             if(mp.find(sum)!=mp.end())
            {
                count+=mp[sum];
            }
            mp[it]++;
        }
        return count;
    }
};