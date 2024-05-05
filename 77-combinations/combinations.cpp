class Solution {
public:
    void solve(int i,vector<vector<int>>&ans,vector<int>&temp,int n,int k)
    {
        if(temp.size()==k)
        {
            ans.push_back(temp);
            return ;
        }
        if(i>n) return ;

        //pick
        temp.push_back(i);
        solve(i+1,ans,temp,n,k);
        temp.pop_back();

        //not-pick
        solve(i+1,ans,temp,n,k);
    }
    vector<vector<int>> combine(int n, int k) {
        int i=1;
        vector<vector<int>>ans;
        vector<int>temp;
        solve(i,ans,temp,n,k);
        return ans;
    }
};