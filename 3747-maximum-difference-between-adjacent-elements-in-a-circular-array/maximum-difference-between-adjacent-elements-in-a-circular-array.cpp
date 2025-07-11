class Solution {
public:
    int maxAdjacentDistance(vector<int>& nums) {
        int ans=INT_MIN;
        int n=nums.size();

        for(int i=1;i<n;i++){
            ans=max(abs(nums[i]-nums[i-1]),ans);
        }

        ans=max(ans,abs(nums[n-1]-nums[0]));

        return ans;
    }
    
};