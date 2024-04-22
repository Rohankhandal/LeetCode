//T.c:-O(2^N);

class Solution {
public:
    int count=0;
    void solve(vector<int>&nums,int k,int i,unordered_map<int,int>&mp)
    {
        if(i==nums.size())
        {
            count++;
            return ;
        } 

        //take
        if(!mp[nums[i]-k] && !mp[nums[i]+k])
        {
            mp[nums[i]]++;
            solve(nums,k,i+1,mp);
            //backtracking
            mp[nums[i]]--;
        }

        //not-take
        solve(nums,k,i+1,mp);
    }
    int beautifulSubsets(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        solve(nums,k,0,mp);
        return count-1;   //bcz there is one empty subset is also included
    }
};