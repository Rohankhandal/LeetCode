class Solution {
public:
    int missingInteger(vector<int>& nums) {
        unordered_map<int,int> mp;
        for(int i=0;i<nums.size();i++)
        {
            mp[nums[i]]++;
        }
        int sum=0;
        int i=0;
        for(i=1;i<nums.size();i++)
        {
            if(nums[i]==nums[i-1]+1)
            {
                sum+=nums[i-1];
            }
            else
            {
                
                break;
            }
        }
        sum+=nums[i-1];
        while(mp[sum]!=0)
        {
            sum++;
        }
        return sum;
    }
};