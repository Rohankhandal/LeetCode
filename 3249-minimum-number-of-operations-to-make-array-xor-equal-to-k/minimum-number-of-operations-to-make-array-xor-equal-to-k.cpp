class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int xorVal=0;
        for(auto &num:nums)
        {
            xorVal^=num;
        }

        int cnt=0;
        while(xorVal>0 || k>0){
            int a=xorVal&1;
            int b=k&1;

            if(a!=b) cnt++;

            if(xorVal>0) xorVal>>=1;
            if(k>0) k>>=1;
        }
        return cnt;
    }
};