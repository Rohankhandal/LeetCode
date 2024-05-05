class Solution {
public:
    void solve(vector<int>& nums,vector<vector<int>>&ans,vector<int>temp,unordered_map<int,int>&mp)
    {
        int n=nums.size();
        if(temp.size()==n)
        {
            ans.push_back(temp);  //o(N) => copy
            return ;
        }

        for(int i=0;i<n;i++)
        {
            if(mp.find(nums[i])==mp.end())
            {
                temp.push_back(nums[i]);
                mp[nums[i]]++;

                solve(nums,ans,temp,mp);

                mp.erase(nums[i]);
                temp.pop_back();
            }
        }
    }
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        unordered_map<int,int>mp;
        solve(nums,ans,temp,mp);
        return ans;
    }
};