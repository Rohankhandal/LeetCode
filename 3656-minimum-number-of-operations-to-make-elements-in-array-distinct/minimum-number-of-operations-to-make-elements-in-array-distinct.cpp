class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        for(auto &it:nums){
            mp[it]++;
        }
        int i=0;
        int cnt=0;
        while(i<n)
        {
            if(mp.size()!=n-i)
            {
                cnt++;
                if(n-i<3)
                {
                    return cnt;
                }
                mp[nums[i]]--;
                if(mp[nums[i]]==0) mp.erase(nums[i]);
                mp[nums[i+1]]--;
                if(mp[nums[i+1]]==0) mp.erase(nums[i+1]);
                mp[nums[i+2]]--;
                if(mp[nums[i+2]]==0) mp.erase(nums[i+2]);
                i+=3;
            }
            else return cnt;
        }
        return cnt;
    }
};