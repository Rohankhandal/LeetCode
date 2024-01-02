class Solution {
public:
    vector<vector<int>> findMatrix(vector<int>& nums) {
        int n=nums.size();
        unordered_map<int,int>mp;           //or vector<int> mp(n+1,0);
        vector<vector<int>>ans;   
        for(int i=0;i<nums.size();i++)
        {
            int freq=mp[nums[i]];
            if(freq==ans.size())
            {
                ans.push_back({});  //insert a new row in 2d vector(IMP PART)
            }
            ans[freq].push_back(nums[i]);
            mp[nums[i]]++;
        }
        return ans;
       
    }
};