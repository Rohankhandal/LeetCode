class Solution {
public:
    vector<int> singleNumber(vector<int>& nums) {
        long long xorValue=0;
        for(auto &it:nums)
        {
            xorValue^=it;
        }

         long long firstUnsetBit=(xorValue&(xorValue-1))^xorValue;
        cout<<firstUnsetBit<<endl;
        int one=0,two=0;
        for(auto &it:nums)
        {
            if(it&firstUnsetBit)  //1
            {
                one^=it;
            }
            else two^=it;
        }
        return {one,two};


    }
};