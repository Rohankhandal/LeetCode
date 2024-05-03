//T.c:-O(2^n)
//S.c:-O(1)
class Solution {
    void solve(int i,int k, int n, vector<vector<int>> & ans,vector<int>temp, int sum){
        if(k==0)
        {
            if(sum==n)
            {
                ans.push_back(temp);
            }
            return ;
        }
        if(sum>n) return ;
        if(i>=10) return ;

        //pick
        temp.push_back(i);
        solve(i+1,k-1,n,ans,temp,sum+i);
        temp.pop_back();


        //not pick
        solve(i+1,k,n,ans,temp,sum);
    }
public:
    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int>temp;
        int i=1;
        int sum=0;
        solve(i,k,n,ans,temp,sum);
        return ans;
    }
};







// class Solution {
//     void solve(int k, int n, vector<vector<int>> & answer ,vector<int>ans , int index){
//         // base case 
//         if(n==0 && ans.size()==k){
//             answer.push_back(ans);
//             return ;
//         }

//         for(int i=index;i<=9;i++){
//             if(i<=n){
//                 ans.push_back(i);
//                 solve(k,n-i,answer,ans,i+1);
//                  ans.pop_back();
//             }
               
//         }
//     }
// public:
//     vector<vector<int>> combinationSum3(int k, int n) {
//         vector<vector<int>> answer;
//         vector<int>ans;

//         solve(k,n,answer,ans,1);
//         return answer;
//     }
// };