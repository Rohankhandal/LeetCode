//Using binary search O(logN)
class Solution {
public:
    int arrangeCoins(int n) {
       long long left=0,high=n;
       int ans=1;
       while(left<=high)
       {
           long mid=left+(high-left)/2;
           long long sum=mid*(mid+1)/2;
           if(sum<=n)
           {
           ans=mid;
           left=mid+1;
           }
           else
           {
               high=mid-1;
           }

       }
       return ans;
    }
};