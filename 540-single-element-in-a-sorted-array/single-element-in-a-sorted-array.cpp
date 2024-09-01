class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int n=nums.size();
        int l=1,r=n-1;
        if(n==1) return nums[0];

        if(nums[0]!=nums[1]) return nums[0];
        if(nums[n-1]!=nums[n-2]) return nums[n-1];

        while(l<=r)
        {
            int mid=(l+r)/2;

            if(nums[mid-1]!=nums[mid] && nums[mid+1]!=nums[mid])
            {
                return nums[mid];
            }

            if((mid%2==1 && (nums[mid]==nums[mid-1])) || (mid%2==0 && (nums[mid]==nums[mid+1])))
            {
                //single element right me hoga
                l=mid+1;
            }
            else
            {
                r=mid-1;
            }
        }
        return -1;
    }
};