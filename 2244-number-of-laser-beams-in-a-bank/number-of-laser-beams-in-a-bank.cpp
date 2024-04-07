class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        int ans=0;
        int prev=0;
        for(auto &it:bank)
        {
            int one=0;
            for(auto &m:it)
            {
                if(m=='1') one++;
            }
            if(prev==0)
            {
                prev=one;
            }
            else
            {
                if(one!=0)
                {
                    ans+=(prev*one);
                    prev=one;
                }
            }
        }
        return ans;
    }
};