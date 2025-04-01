class Solution {
public:
    int arrayPairSum(vector<int>& nums) {
        int ans=0;
        sort(nums.begin(),nums.end());
        int n=nums.size();
        for(int i=0;i<n;i+=2)
        {
            ans+=min(nums[i],nums[i+1]);
        }
        return ans;
    }
};