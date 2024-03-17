class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int index=0;
        for(auto &it:nums)
        {
            if(it!=0)
            {
                nums[index++]=it;
            }
        }
        //now fill remaining cell with zero
        for(int i=index;i<nums.size();i++)
        {
            nums[i]=0;
        }
        return ;
    }
};