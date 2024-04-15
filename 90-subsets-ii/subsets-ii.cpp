class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        set<vector<int>>st;
        int n=nums.size();
        vector<vector<int>>ans;
        int total=pow(2,n);
        for(int i=0;i<total;i++)
        {
            vector<int>temp;
            for(int j=0;j<n;j++)
            {
                if((i>>j) & 1)
                {
                    temp.push_back(nums[j]);
                }
            }
            sort(temp.begin(),temp.end());
            st.insert(temp);
        }
        for(auto &i:st)
        {
            ans.push_back(i);
        }
        return ans;
    }
};