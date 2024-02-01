class Solution {
public:
    vector<vector<int>> divideArray(vector<int>& nums, int k) {
        vector<vector<int>>ans;
        int n=nums.size();
        sort(nums.begin(),nums.end());
        for(int i=0;i<n-2;i=i+3)
        {
            if(nums[i+2]-nums[i]<=k)
            {
                vector<int>temp;
                for(int j=i;j<=i+2;j++)
                {
                    temp.push_back(nums[j]);
                }
                ans.push_back(temp);
            }
            else
            {
                 vector<vector<int>>ans;
                return ans;
            }
        }
        return ans;
    }
};