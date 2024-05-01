class Solution {
    void solve(int k, int n, vector<vector<int>> & answer ,vector<int>ans , int index){
        // base case 
        if(n==0 && ans.size()==k){
            answer.push_back(ans);
            return ;
        }

        for(int i=index;i<=9;i++){
            if(i<=n){
                ans.push_back(i);
                solve(k,n-i,answer,ans,i+1);
                 ans.pop_back();
            }
               
        }
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> answer;
        vector<int>ans;

        solve(k,n,answer,ans,1);
        return answer;
    }
};