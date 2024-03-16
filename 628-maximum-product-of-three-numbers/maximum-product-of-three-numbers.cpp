class Solution {
public:
    static bool cmp(int a,int b)
    {
        return a>b;
    }
    int maximumProduct(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       
       //starting two negative and last one ele
       int max1=nums[0]*nums[1]*nums[n-1];
       int max2=nums[n-1]*nums[n-2]*nums[n-3];
       return max(max1,max2);
    }
};