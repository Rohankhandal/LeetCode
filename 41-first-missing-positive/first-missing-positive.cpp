class Solution {
public:
    int firstMissingPositive(vector<int>& nums) {
        int n=nums.size();
        vector<bool>mark(n+1,false);
        for(auto &it:nums)
        {
            if(it>=0 && it<=n)
                mark[it]=true;
        }
        for(int i=1;i<n+1;i++){    //traverse from index 1
            if(mark[i]==false)
                return i;
        }
        return n+1;
       
    }
};