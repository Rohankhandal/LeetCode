class Solution {
public:
    void solve(vector<vector<int>>&ans,vector<int>temp,vector<int>&v,int k,int n,int i,int sum)
    {
        if(k==0)
        {
            if(sum==n)
              ans.push_back(temp);
            return ;
        }
        if(i>=v.size()) return; 

            //include
            temp.push_back(v[i]);
            solve(ans,temp,v,k-1,n,i+1,sum+v[i]);
            temp.pop_back();

            //exlcude
            solve(ans,temp,v,k,n,i+1,sum);
    }
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<int>v={1,2,3,4,5,6,7,8,9};
        // for(auto &it:v)
        // {
        //     cout<<it<<" ";
        // }
        vector<vector<int>>ans;
        vector<int>temp;
        solve(ans,temp,v,k,n,0,0);
        return ans;
    }
};