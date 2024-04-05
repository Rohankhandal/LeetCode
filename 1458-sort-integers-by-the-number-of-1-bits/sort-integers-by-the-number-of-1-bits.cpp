class Solution {
public:
    vector<int> sortByBits(vector<int>& arr) {
        vector<int>ans=arr;
        auto mycmp=[](int &a,int&b)
        {
            int bit1=__builtin_popcount(a);
            int bit2=__builtin_popcount(b);
            if(bit1==bit2)
            {
                return a<b;
            }
            else
            {
                return bit1<bit2;
            }
            
        };
        sort(ans.begin(),ans.end(),mycmp);
        return ans;
    }
};