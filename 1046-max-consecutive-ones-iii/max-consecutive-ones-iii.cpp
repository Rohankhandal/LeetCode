class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int right=0,left=0;
        int ans=0;
        while(right<nums.size())
        {
            mp[nums[right]]++;
            if(right-left+1-mp[1]>k)
            {
                mp[nums[left]]--;
                left++;

            }
            
            ans=max(right-left+1,ans);
            right++;
        }
        return ans;

    }
};