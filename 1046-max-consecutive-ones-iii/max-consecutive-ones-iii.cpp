//Means atmost K 0 is possible in our window
class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
      int left=0,right=0,maxOnes=0,zeroCount=0;
      while(right<nums.size())
      {
          if(nums[right]==0)
          {
              zeroCount++;
          }
          while(zeroCount>k)
          {
              if(nums[left]==0)
              {
                  zeroCount--;
              }
              left++;
          }
          maxOnes=max(maxOnes,right-left+1);
          right++;
      }
      return maxOnes;
    }
};
// T.C:-O(n) S.C :O(n)  sliding window
// class Solution {
// public:
//     int longestOnes(vector<int>& nums, int k) {
//         unordered_map<int,int>mp;
//         int right=0,left=0;
//         int ans=0;
//         while(right<nums.size())
//         {
//             mp[nums[right]]++;
//             if(right-left+1-mp[1]>k)
//             {
//                 mp[nums[left]]--;
//                 left++;

//             }
            
//             ans=max(right-left+1,ans);
//             right++;
//         }
//         return ans;

//     }
// };