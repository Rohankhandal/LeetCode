class Solution {
public:
    void solve(vector<int>&nums,int i,vector<vector<int>>&ans,vector<int>temp)
    {
        int n=nums.size();
        if(i>=nums.size())
        {
            ans.push_back(temp);
            return ;
        }

        for(int j=i;j<n;j++)
        {
            swap(temp[i],temp[j]);
            solve(nums,i+1,ans,temp);
            swap(temp[i],temp[j]);
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp=nums;
        int i=0;
        solve(nums,i,ans,temp);
        return ans;

    }
};