//Approach-2 (Using sliding window)
//T.C : O(nlogn)
//S.C : O(1)
class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());   //bcz a number is only ask for increase which is less than the 
    //current index value
        int l=0,r=0;
        int n=nums.size();
        int ans=0;
        long long currSum=0;
        while(r<n)
        {
            long long target=nums[r];
            currSum+=nums[r];

            while((r-l+1)*target - currSum >k)  //also work if we use if instead while 
            // if((r-l+1)*target - currSum >k)
            {
                currSum-=nums[l];
                l++;
            }


            ans=max(ans,r-l+1);
            r++;
        }
        return ans;
       
    }
};




//Approach-1 (Using Binary Search)
//T.C : O(nlogn)
//S.C : O(n) for prefixSum for effienctly calculating windowSum
// class Solution {
// public:
//     int binarySearch(int target_idx,vector<int>&nums,vector<long long>&prefixSum,int k)
//     {
//         int target=nums[target_idx];
//         int i=0;
//         int j=target_idx;
//         int result = target_idx;
        
//         while(i <= j) {
//             int mid = i + (j-i)/2;
            
//             long count      = (target_idx - mid + 1);
//             long windowSum  = (count * target);
//             long currSum    = prefixSum[target_idx] - prefixSum[mid] + nums[mid];  //DRY RUN 
            
//             int ops         = windowSum - currSum;
            
//             if(ops > k ) {
//                 i = mid+1;
//             } else {
//                 result = mid;//posssible find largest window,that's why store the answer
//                 j = mid-1;    
//             }
//         }
        
//         return target_idx-result+1;
//     }
//     int maxFrequency(vector<int>& nums, int k) {
//         sort(nums.begin(),nums.end());   //bcz a number is only ask for increase which is less than the 
//     //current index value
//         int n=nums.size();
//         vector<long long>prefix(n);
//         prefix[0]=nums[0];
//         for(int i=1;i<n;i++)
//         {
//             prefix[i]=nums[i]+prefix[i-1];
//         }  
//         int result=0;
//         for(int target_idx=0;target_idx<n;target_idx++)
//         {
//             result=max(result,binarySearch(target_idx,nums,prefix,k));
//         }
//         return result;
//     }
// };