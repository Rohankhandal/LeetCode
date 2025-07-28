class Solution {
public:
    int countMaxOrSubsets(vector<int>& nums) {
       int n=nums.size();
       int maxOr=0;
       for(auto &num:nums)
       {
        maxOr|=num;
       }
       int cnt=0;

       int total=(1<<n);
       for(int i=0;i<total;i++)
       {
         int orVal=0;
         for(int j=0;j<n;j++)
         {
            if(i&(1<<j)){
                orVal|=nums[j];
            }
         }
      
         cnt+=(orVal==maxOr);
       }
       return cnt;
    }
};