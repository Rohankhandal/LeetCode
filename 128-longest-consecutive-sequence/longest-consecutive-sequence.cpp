class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
      int n=nums.size();
      unordered_map<int,int>mp;
      for(int i=0;i<n;i++)
      {
        mp[nums[i]]++;
      }   
    int maxLen=0;
      for(int i=0;i<n;i++)
      {
        int cnt=0;
        if(mp.find(nums[i]-1)==mp.end())
        {
            int start=nums[i];
            int cnt=0;
            while(mp.find(start)!=mp.end())
            {
                start++;
                cnt++;
            }
            maxLen=max(maxLen,cnt);
        }
      }
      return maxLen;
    }
};