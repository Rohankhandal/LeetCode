class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        int len1=nums1.size();
        int len2=nums2.size();
        vector<int>ans(len1,0);
        for(int i=0;i<len1;i++)
        {
            int num=nums1[i];
            int maxEle=num;
            for(int j=len2-1;j>=0;j--)
            {
               if(num==nums2[j])
               {
                   if(maxEle==num)
                   {
                       ans[i]=-1;
                   }
                   else
                   {
                        ans[i]=maxEle;
                   break;
                   }
                  
               }
               if(nums2[j]>num)
               {
                   maxEle=nums2[j];
               }
            }
        }
        return ans;
    }
};