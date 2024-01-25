class Solution {
public:
    void sortColors(vector<int>& nums) {
        int n=nums.size();
     int l=0,m=0,e=n-1;

     while(m<=e)
     {
         if(nums[m]==0)
         {
             swap(nums[l],nums[m]);
             l++;
             m++;
         }
         else if(nums[m]==1)
         {
             m++;
         }
         else
         {
             swap(nums[m],nums[e]);
             e--;
         }
     }   
    }
};