//Using two pointer 
// tc:-min(n,m)
// sc:-1

// class Solution {
// public:
//     int maxDistance(vector<int>& nums1, vector<int>& nums2) {
//         int n = nums1.size();
//         int m = nums2.size();
//         int c=0,i=0,j=0;
        
//                while (i < n && j < m)
//             if (nums1[i] > nums2[j])
//                 i++;
//             else{
//                 c = max(c, j - i);
//                 j++;
//             }
//             return c;
        
//     }
// };


//use binary search on num2 to find valid j
// T.c:-O(NlogN)
// S.C:-O(1)
class Solution {
public:
    int maxDistance(vector<int>& arr1, vector<int>& arr2) {
        int n = arr1.size(),m = arr2.size(),ans = 0;
        for(int i = 0;i<n;i++)
        {
            int ind = -1,left = i,right = m-1;
            while(left<=right)
            {
              int mid = (left+right)/2;
              if(arr2[mid]>=arr1[i])
              {
                ind = mid;
                left = mid+1;
              }
              else
              right = mid-1;
            }
            if(ind!=-1) ans = max(ans,ind-i);
        }
        return ans;
        
    }
};