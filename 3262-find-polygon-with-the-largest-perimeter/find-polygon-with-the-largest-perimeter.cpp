class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n=nums.size();
        sort(nums.begin(),nums.end());
        long long preSum=0;
        long long maxPerimeter=-1;  //bcz no negative value in array
        for(int i=0;i<2;i++)
        {
            preSum+=nums[i];
        }
        for(int i=2;i<n;i++)
        {
            if(preSum>nums[i])
            {
                preSum=preSum+nums[i];
                if(maxPerimeter<preSum)
                {
                    maxPerimeter=preSum;
                }
            }
            else{
                preSum+=nums[i];
            }
        }
        return maxPerimeter;
    }
};