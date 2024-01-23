class Solution {
public:
    int arraySign(vector<int>& nums) {
        int product=1;
        for(auto &it:nums)
        {
            if(it==0)
            {
                return 0;
            }
            else if(it<0)
            {
                it=-1;
            }
            else
            {
                it=1;
            }
            product*=it;
        }
      
        return product;
    }
};