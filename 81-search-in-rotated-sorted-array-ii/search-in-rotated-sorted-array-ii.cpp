class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n=nums.size();
        int l=1,r=n-2;
        if(nums[0]==target || nums[n-1]==target) return true;
        while(l<=r)
        {
            while(l<=r && nums[l]==nums[l-1]) l++;
            if(l>r) break;
            while(l<=r && nums[r]==nums[r+1]) r--;
            if(l>r) break;

            int mid=l+(r-l)/2;

            if(nums[mid]==target)
            {
                return true;
            }
            else if(nums[l]<=nums[mid])
            {
                if(nums[l]<= target &&  target <=nums[mid])
                {
                    r=mid-1;
                }
                else 
                {
                    l=mid+1;
                }
            }
            else if(nums[mid]<=nums[r])
            {
                if(nums[mid]<= target &&  target <=nums[r])
                {
                    l=mid+1;
                }
                else 
                {
                    r=mid-1;
                }
            }
        }
        return false;
    }
};