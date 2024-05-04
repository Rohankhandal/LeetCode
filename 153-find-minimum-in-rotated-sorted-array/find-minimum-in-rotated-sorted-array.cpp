class Solution {
public:
    int findMin(vector<int>& nums) {
        int n=nums.size();
        int l=0,r=nums.size()-1;
        int ans=INT_MAX;
        if(n==1) return nums[0];
        if(n==2)
        {
            return min(nums[0],nums[1]);
        }
       
        while(l<=r)
        {
            int mid=(l+r)/2;
            if(nums[0]<=nums[mid])  //left part is sorted
            {
               ans=min(nums[0],ans);
               l=mid+1;
            }
            else
            {
                ans=min(nums[mid],ans);
                r=mid-1;
            }
        }
        return ans;

    }
};