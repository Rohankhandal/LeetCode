class Solution {
public:
    void solve(vector<int>&cand,vector<vector<int>>&ans,vector<int>temp,int i,int sum,int &target)
    {
         if(sum==target)
         {
            ans.push_back(temp);
            return ;
         }
         if(sum>target) return ;
            
        if(i>=cand.size())
        {
           return ;
        }
        //take
        temp.push_back(cand[i]);
        solve(cand,ans,temp,i+1,sum+cand[i],target);
        temp.pop_back();

        //not-take
        while(i+1<cand.size() && cand[i]==cand[i+1]) i++;   //IMP IGONRE ALL DUPLICATE SUBSEQUENCE
        solve(cand,ans,temp,i+1,sum,target);
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        vector<vector<int>>ans;
        vector<int>temp;
        int sum=0;
        solve(candidates,ans,temp,0,sum,target);
        return ans;
        
    }
};