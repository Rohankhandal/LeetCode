class Solution {
public:
    bool isOk(vector<int>&nums1,vector<int>&nums2,int& diff)
    {
        int cnt=0;
         int n=nums1.size();
        int m=nums2.size();
        int j=0;
        for(int i=0;i<n&&j<m;i++)
        {
            int diffVal=nums2[j]-nums1[i];
            if(diffVal==diff)
            {
                j++;
            }
            else{ cnt++;}
        }
        return (cnt<=2)?true:false;
       
    }
    int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {  //T.C:-O(N^3)
        
        sort(nums1.begin(),nums1.end());
        sort(nums2.begin(),nums2.end());
        int n=nums1.size();
        int m=nums2.size();
        int mini=INT_MAX;
        for(int i=0;i<n;i++)  
        {
            int diff=nums2[0]-nums1[i];
            if(isOk(nums1,nums2,diff))
            {
                mini=min(diff,mini);
            }
        }
        return mini;
    }
};




//T.C:-O(N^3) =>Brute Force
// class Solution {
// public:
//     bool isOk(vector<int>&nums1,vector<int>&nums2,int i,int j,int& diff)
//     {
//         int n = nums1.size();
//         int m = nums2.size();
//         for (int k = 0, l = 0; k < n && l < m;) {
//             if (k == i || k==j) {
//                 k++;
//                 continue;
//             }
           
//             int val = nums2[l] - nums1[k];
//             if (diff == INT_MAX) {
//                 diff = val;
//             } else if (diff != val) {
//                 return false;
//             }
//             k++;
//             l++;
//         }
//         return true;
//     }
//     int minimumAddedInteger(vector<int>& nums1, vector<int>& nums2) {  //T.C:-O(N^3)
//         int ans=0;
//          sort(nums1.begin(),nums1.end());
//         sort(nums2.begin(),nums2.end());
//         int n=nums1.size();
//         int m=nums2.size();
//         int mini=INT_MAX;
//         for(int i=0;i<n-1;i++)  //remove i and j index element
//         {
//             for(int j=i+1;j<n;j++)
//             {
//                int diff=INT_MAX;
//                if(isOk(nums1,nums2,i,j,diff))
//                {
//                 mini=min(mini,diff);
//                }
//             }
//         }
//         return mini;
//     }
// };