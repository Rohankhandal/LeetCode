class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
        int s=0;
        int e=nums.size()-1;
        int ans=-1;
       while(s<=e)
       {
           int mid=(s+e)/2;
            if(nums[mid]==target)
            {
                return mid;
            }
            else if(nums[mid] > target)
            {
                e = mid - 1;
                // ans = mid;
            }
            else
            {
                s = mid + 1;
                // ans = s;
            }
        }
        return s;
    }
};