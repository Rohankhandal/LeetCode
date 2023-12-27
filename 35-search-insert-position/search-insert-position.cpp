class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int ans=-1;
        for(int i=0;i<nums.size();i++)
        {
            if(nums[i]==target)
            {
                return i;
            }
            else 
            {
                if(nums[i]>target)
                break;

                ans=i;
            }
        }
        return ans+1;
    }
};