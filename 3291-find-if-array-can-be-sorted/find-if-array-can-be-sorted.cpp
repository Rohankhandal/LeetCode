class Solution {
public:
    bool canSortArray(vector<int>& nums) {
        int n=nums.size();

        for(int i=0;i<n-1;i++)
        {
            bool swapped=false;
            for(int j=0;j<n-i-1;j++)
            {
                int bitA=__builtin_popcount(nums[j]);
                int bitB=__builtin_popcount(nums[j+1]);

                if(nums[j]>nums[j+1] && bitA==bitB)
                {
                    swapped=true;
                    swap(nums[j],nums[j+1]);
                }
                else if(nums[j]>nums[j+1]) return false;
            }
            if(!swapped) break;
        }


        return is_sorted(nums.begin(),nums.end());
    }
};