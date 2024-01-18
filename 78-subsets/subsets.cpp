class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
         vector<vector<int>>ans;
         int n=nums.size();
        //  int total=pow(2,n);
         for(int i=0;i<1<<n;i++)    //total=1<<n;
         {
             vector<int>temp;
             for(int j=0;j<nums.size();j++)
             {
                 if((i>>j)&1)
                 {
                     temp.push_back(nums[j]);
                   
                 }
             }
             ans.push_back(temp);
         }
         return ans;
    }
};