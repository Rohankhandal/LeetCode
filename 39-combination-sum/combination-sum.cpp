class Solution {
public:
    void solve(int idx,vector<int>&nums,int tar,vector<vector<int>>&ans,vector<int>temp)
    {
        
        if(tar==0)
        {
            ans.push_back(temp);
            return ;
        }
        if(tar<0) return ;
        for(int i=idx;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            solve(i,nums,tar-nums[i],ans,temp);
            temp.pop_back();
        }
    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>>ans;
        vector<int>temp;
        solve(0,candidates,target,ans,temp);
        return ans;
    }
};