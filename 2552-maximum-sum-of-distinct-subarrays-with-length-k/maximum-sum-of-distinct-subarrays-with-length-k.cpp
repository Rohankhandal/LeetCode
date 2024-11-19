class Solution {
public:
    long long maximumSubarraySum(vector<int>& nums, int k) {
        long long ans=0;
        int n=nums.size();
        unordered_map<int,int>mp;
        long long  sum=0;
        
        for(int i=0;i<k;i++)
        {
            mp[nums[i]]++;
            sum+=nums[i];
        }

        if(mp.size()==k)  ans=static_cast<long long>(max(ans,sum));
        int l=0,r=k;
        while(r<n)
        {
            mp[nums[l]]--;
            sum-=nums[l];
            
            mp[nums[r]]++;
            sum+=nums[r];

            if(mp[nums[l]]==0) mp.erase(nums[l]);
            l++;
            
            if(mp.size()==k) ans=static_cast<long long>(max(ans,sum));

            r++;

        }
        return ans;
    }
};