class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int l=0,r=0;
        int n=nums.size();
        int minLen=INT_MAX;
        int sum=0;
        while(r<n)
        {
            sum+=nums[r];

            while(l<=r && sum>=target)
            {
                 if(sum>=target)
                {
                    minLen=min(minLen,r-l+1);
                }
                sum-=nums[l];
                l++;
            }

           
            r++;
        }
        return minLen==INT_MAX?0:minLen;
    }
};



// class Solution {
// public:
//     int minSubArrayLen(int target, vector<int>& nums) {
//         int i=0,j=0;
//         int sum=0;
//         int len=INT_MAX;

//         while(j<nums.size())
//         {
//             //include current number;
//             sum+=nums[j];
//             //mere pas ek window ka sum ready ha
//             while(sum>=target)
//             {
//                 //minimize->sum me se decrease karo,len bhi update krelena,i/start ko aage badhana padega

//                 len=min(len,j-i+1);
//                 sum=sum-nums[i];
//                 i++;
//             }
//             j++;
//         }

//         if(len==INT_MAX)
//             return 0;
//         else 
//             return len;
        
       
//     }
// };