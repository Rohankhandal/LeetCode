class Solution {
public:
    int maxSubarrayLength(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int l=0,r=0;
        int n=nums.size();
        int ans=0;
        while(r<n)
        {
            if(mp.find(nums[r])!=mp.end() && mp[nums[r]]>=k)
            {
                while(l<r && mp[nums[r]]>=k)
                {
                    mp[nums[l]]--;
                    l++;
                }
            }

            mp[nums[r]]++;
            ans=max(ans,r-l+1);
            r++;
        }
        for(auto it:mp)
        {
            cout<<it.first<<" "<<it.second<<endl;
        }
        return ans;
    }
};