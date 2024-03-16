class Solution {
public:
    static bool cmp(int a,int b)
    {
        return a>b;
    }
    int maximumProduct(vector<int>& nums) {
       sort(nums.begin(),nums.end());
       int n=nums.size();
       int maxLast=1,count=0;
       int maxStart=1;
       int i=n-1;
       while(count!=3)
       {
        maxLast*=nums[i];
        count++;
        i--;
       }
       i=0;
       count=0;
       while(count!=3)
       {
        maxStart*=nums[i];
        i++;
        count++;
       }
       //starting two negative and last one ele
       int maxi=nums[0]*nums[1]*nums[n-1];
       return max(maxStart,max(maxi,maxLast));
    }
};