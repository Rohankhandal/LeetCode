class Solution {
public:
    int maximumProduct(vector<int>& nums) {
      int n=nums.size();
      int firstMin=INT_MAX,secondMin=INT_MAX;
      int firstMax=INT_MIN,secondMax=INT_MIN,thirdMax=INT_MIN;
      for(int i=0;i<n;i++)
      {
        if(nums[i]>firstMax)
        {
            thirdMax=secondMax;
            secondMax=firstMax;
            firstMax=nums[i];
        }
        else if(nums[i]>secondMax)
        {
            thirdMax=secondMax;
            secondMax=nums[i];
        }
        else if(nums[i]>thirdMax)
        {
            thirdMax=nums[i];
        }


        if(nums[i]<firstMin)
        {
            secondMin=firstMin;
            firstMin=nums[i];
        }
        else if(nums[i]<secondMin)
        {
            secondMin=nums[i];
        }
       
      }
    //   cout<<firstMin<<" "<<secondMin<<endl;
      int max1=firstMin*secondMin*firstMax;
      int max2=firstMax*secondMax*thirdMax;
    return max(max1,max2);
    }
      
};
// class Solution {
// public:
//     int maximumProduct(vector<int>& nums) {
//        sort(nums.begin(),nums.end());
//        int n=nums.size();
       
//        //starting two negative and last one ele
//        int max1=nums[0]*nums[1]*nums[n-1];
//        int max2=nums[n-1]*nums[n-2]*nums[n-3];
//        return max(max1,max2);
//     }
// };