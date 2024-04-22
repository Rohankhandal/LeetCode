class Solution {
public:
    int solve(vector<int>&nums,int k,int i,unordered_map<int,int>&mp)
    {
        if(i==nums.size()) return 1;

        //take
        int take=0;
        if(!mp[nums[i]-k] && !mp[nums[i]+k])
        {
            mp[nums[i]]++;
            take=solve(nums,k,i+1,mp);
            //backtracking
            mp[nums[i]]--;
        }

        //not-take
        int noTake=solve(nums,k,i+1,mp);

        return take+noTake;
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int ans=solve(nums,k,0,mp);
        return ans-1;   //bcz there is one empty subset is also included
    }
};