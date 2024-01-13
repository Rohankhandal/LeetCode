class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        int res=nums[0];
        for(int i=1;i<nums.size();i++)
        {
            res=res^nums[i];
        }
        int ans=0;
        while(k!=0 || res!= 0)         //here instead of and , we use or 
        {
            if((k&1)!=(res&1))
            {
                ans++;
            }
            res=res>>1;
            k=k>>1;
        }
        // while(k!=0)  //no use if we make or operation instead of and opreation
        // {
        //     if((k&1)==1)
        //     ans++;
        //     k=k>>1;
        // }
        // while(res!=0)
        // {
        //     if((res&1)==1)
        //     ans++;
        //     res=res>>1;
        // }
        return ans;


    }
};