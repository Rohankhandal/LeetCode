class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;
        int l=0,r=0;
        int sum=0;
        int ans=0;
        while(r<n)
        {
            mp[nums[r]]++;
            sum+=nums[r];

            while(l<=r && mp[nums[r]]>1)
            {
                mp[nums[l]]--;
                if(mp[nums[l]]==0) mp.erase(nums[l]);
                sum-=nums[l];
                l++;
            }

            ans=max(ans,sum);
            r++;
        }

        return ans;
    }
};