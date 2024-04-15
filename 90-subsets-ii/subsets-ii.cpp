class Solution {
public:
    void solve(vector<int>&nums,vector<vector<int>>&ans,vector<int>temp,int i)
    {
        if(i>=nums.size())
        {
            ans.push_back(temp);
            return ;
        }
        //take
        temp.push_back(nums[i]);
        solve(nums,ans,temp,i+1);
        temp.pop_back();

        //not-take
        //skip all duplicate elements for current index i value
        while(i+1<nums.size() && nums[i]==nums[i+1]) i++;
        solve(nums,ans,temp,i+1);
    }
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>>ans;
        vector<int>temp;
        int index=0;
        sort(nums.begin(),nums.end());  //sort bcz for all duplicate elements comes together
        solve(nums,ans,temp,index);

        return ans;
    }
};




//ITERATIVE METHOD

// class Solution {
// public:
//     vector<vector<int>> subsetsWithDup(vector<int>& nums) {
//         set<vector<int>>st;
//         int n=nums.size();
//         vector<vector<int>>ans;
//         int total=pow(2,n);
//         for(int i=0;i<total;i++)
//         {
//             vector<int>temp;
//             for(int j=0;j<n;j++)
//             {
//                 if((i>>j) & 1)
//                 {
//                     temp.push_back(nums[j]);
//                 }
//             }
//             sort(temp.begin(),temp.end());
//             st.insert(temp);
//         }
//         for(auto &i:st)
//         {
//             ans.push_back(i);
//         }
//         return ans;
//     }
// };