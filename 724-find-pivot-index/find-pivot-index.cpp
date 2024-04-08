class Solution {
public:
    int pivotIndex(vector<int>& nums) {
        int n=nums.size();
        int totalSum=0;
        for(auto &it:nums)
        {
            totalSum+=it;
        }
        int leftSum=0;
        for(int i=0;i<n;i++)
        {
            if(i!=0)
                leftSum+=nums[i-1];
            
            int rightSum=totalSum-(leftSum+nums[i]);

            // cout<<leftSum<<" "<<rightSum<<endl;
            // if(i==n-1)
            // {
            //     if(leftSum==0) return i;
            // }
            if(leftSum==rightSum) return i;
        }
        return -1;
    }
};