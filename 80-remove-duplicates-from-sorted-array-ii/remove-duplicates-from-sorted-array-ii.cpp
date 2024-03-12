class Solution {
public:
    int removeDuplicates(vector<int>& nums) {
        int index=1;
        int cnt=1;
        for(int i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1])
            {
                cnt++;
                if(cnt<=2)
                {
                    nums[index++]=nums[i];
                }

            }
            else
            {
                cnt=1;
                nums[index++]=nums[i];
            }
        }
        return index;
    }
};