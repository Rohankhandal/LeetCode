class Solution {
public:
    void solve(int idx,vector<int>&nums,set<vector<int>>&st)
    {
        int n=nums.size();
        if(idx==n)
        {
            for(auto &it:nums)
            {
                cout<<it<<" ";
            }
            cout<<endl;
            st.insert(nums);
            return ;
        }

        for(int i=idx;i<n;i++)
        {
            swap(nums[i],nums[idx]);

            solve(idx+1,nums,st);  //send idx+1 , not i+1

            swap(nums[i],nums[idx]);
        
        }

    }
    vector<vector<int>> permuteUnique(vector<int>& nums) {
        set<vector<int>>st;
        vector<vector<int>>ans;
      
        solve(0,nums,st);

        for(auto &it:st)
        {
            ans.push_back(it);
        }
        return ans;
    }
};