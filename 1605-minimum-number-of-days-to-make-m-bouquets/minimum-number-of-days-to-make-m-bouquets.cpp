class Solution
{
    public:
        bool isPossible(vector<int> &arr, int tar, int m, int k)
        {
            int count = 0;
            int total = 0;
            int i;
            for (i = 0; i < arr.size(); i++)
            {
                if (arr[i] <= tar)
                {
                    count++;
                }
                else
                {
                    total += count / k;
                    count = 0;
                }
            }
            total += count / k;

            if (total >= m)
                return true;
            else
                return false;
        }
    int minDays(vector<int> &bloomDay, int m, int k)
    {
        int mini = *min_element(bloomDay.begin(), bloomDay.end());
        int max = *max_element(bloomDay.begin(), bloomDay.end());
        int l=mini;
        int r=max;
        int ans=-1;
        while(l<=r)
        {
            int mid=l+(r-l)/2;
            if(isPossible(bloomDay,mid,m,k))
            {
                ans=mid;
                r=mid-1;
            }
            else
            {
                l=mid+1;
            }
        }

        return ans;
    }
};
//BRUTE FORCE TLE
// class Solution {
// public:
// bool isPossible(vector<int>&arr, int tar,int m,int k)
// {
//     int count=0;
//     int total=0;
//     int i;
//     for(i=0;i < arr.size();i++)
//     {
//         if(arr[i]<=tar)
//         {
//             count++;
//         }
//         else
//         {
//             total+=count/k;
//             count=0;
//         }
//     }
//       total+=count/k;

//     if(total>=m)
//         return true;
//     else
//         return false;
// }
//     int minDays(vector<int>& bloomDay, int m, int k) {
//         int mini=*min_element(bloomDay.begin(),bloomDay.end());
//         int max=*max_element(bloomDay.begin(),bloomDay.end());
//         for(int i=mini;i<=max;i++)
//         {
//             if(isPossible(bloomDay,i,m,k)){
//                 return i;
//             }
//         }

//         return -1;
//     }
// };