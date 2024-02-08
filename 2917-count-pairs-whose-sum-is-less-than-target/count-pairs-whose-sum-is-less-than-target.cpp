class Solution {
public:
    int countPairs(vector<int>& nums, int target) {
     sort(nums.begin(),nums.end());
     int n=nums.size();
     int start=0;
     int end=n-1;
     int ans=0;
     if(n==1)
     {
         return 0;
     }
     while(start<end)
     {
         int sum=nums[start]+nums[end];
         if(sum<target)
         {
             ans=ans+(end-start);
             start++;
         }
         else {
             end--;
         }
     }  
     return ans; 
    }
};