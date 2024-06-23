class Solution {
public:
    int minimumOperations(vector<int>& nums) {
        int ans=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            ans+=(min(nums[i]%3,3-nums[i]%3));
        }
        return ans;
    }
};