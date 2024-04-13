class Solution {
public:
    void solve(vector<int>&nums,int tar,set<vector<int>>&st,vector<int>temp)
    {
        if(tar==0)
        {
            sort(temp.begin(),temp.end());
            st.insert(temp);
            return ;
        }
        if(tar<0)
        {
            return ;
        }
        for(int i=0;i<nums.size();i++)
        {
            temp.push_back(nums[i]);
            solve(nums,tar-nums[i],st,temp);
            temp.pop_back();
        }

    }
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<int>temp;
        vector<vector<int>>ans;
        set<vector<int>>st;
        solve(candidates,target,st,temp);
        
        for(auto &it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};