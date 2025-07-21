class Solution {
public:
    int f(vector<int>&nums,int goal)
    {
        int n=nums.size();
        int l=0,r=0;
        int ans=0;int sum=0;

        while(r<n)
        {
            sum+=nums[r];

            while(l<=r && sum>goal)
            {
                sum-=nums[l];
                l++;
            }

            ans+=(r-l+1);

            r++;
        }
        return ans;
    }
    int numSubarraysWithSum(vector<int>& nums, int goal) {
      return f(nums,goal)-f(nums,goal-1);
    }
};

// class Solution {
// public:
//     int numSubarraysWithSum(vector<int>& nums, int goal) {
//      int n=nums.size();
//      unordered_map<int,int>mp;  
//      int ans=0;
//      int sum=0; 
//      mp[0]=1;
//      for(int i=0;i<n;i++)
//      {
//         sum+=nums[i];
//         if(mp.find(sum-goal)!=mp.end())
//         {
//             ans+=mp[sum-goal];
//         }

//         mp[sum]++;
//      }

//      return ans;
//     }
// };