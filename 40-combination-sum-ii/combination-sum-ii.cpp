class Solution {
public:
    void solve(vector<int>& arr, int target,vector<vector<int>>&ans,vector<int>&temp,int i)
    {
        if(target<0) return ;
        if(target==0)
        {
            ans.push_back(temp);
            return ;
        }
        if(i>=arr.size())
        {
            return ;
        }

        
        temp.push_back(arr[i]);
        solve(arr,target-arr[i],ans,temp,i+1);
        temp.pop_back();

        //noTake
        int k=i+1;
        while(k<arr.size() && arr[k]==arr[i]) k++;
        solve(arr,target,ans,temp,k);

    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        solve(candidates,target,ans,temp,0);
        return ans;
    }
};