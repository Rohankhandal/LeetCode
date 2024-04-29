class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorVal=0;
        for(auto &i:nums)
        {
            xorVal^=i;
        }
        int ans=0;
        while(xorVal || k)
        {
            if((xorVal&1) != (k&1))
            {
                ans++;
            }
            xorVal>>=1;
            k>>=1;
        }
        return ans;
    }
};