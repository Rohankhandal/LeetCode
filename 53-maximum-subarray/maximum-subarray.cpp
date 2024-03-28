class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int ans=INT_MIN;
        // int sum=0;
        int currSum=0;
        int n=nums.size();
        for(int i=0;i<n;i++)
        {
            if(currSum<0)
            {
                currSum=0;
            }
            
                currSum+=nums[i];
                ans=max(ans,currSum);
            
            cout<<i<<" "<<currSum<<endl;
        }
        return ans;
    }
};