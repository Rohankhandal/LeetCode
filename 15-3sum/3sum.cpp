class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(),nums.end());
        vector<vector<int>>ans;
        int n=nums.size();
        int i=0;
        while(i<n)
        {
            while(i>0 && i<n && nums[i]==nums[i-1]) i++;

            if(i>=n) break;
            int target=-(nums[i]);
            //two sum logic on rest of array

            int l=i+1;
            int r=n-1;
            while(l<r)
            {
                if(nums[l]+nums[r]==target)
                {
                    ans.push_back({-target,nums[l],nums[r]});
                    l++;
                    r--;
                    while(l<r && nums[l]==nums[l-1]) l++;
                    while(l<r && nums[r]==nums[r+1]) r--;
                }
                else if(nums[l]+nums[r]<target)
                {
                    l++;
                }
                else 
                {
                    r--;
                }
            }
            i++;
        }
        return ans;
    }
};