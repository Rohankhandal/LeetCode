class Solution {
public:
    void solve(vector<string>&ans,string temp,int open,int close,int n)
    {
        if(close>open) return ;  //IMP LINE
        if(temp.size()==2*n)
        {
            // cout<<temp<<" "<<open<<" "<<close<<endl;
            if(open==close)
            ans.push_back(temp);
            return;
        }
        
        temp.push_back('(');
        solve(ans,temp,open+1,close,n);
        temp.pop_back();

        if(close<open)
        {
         temp.push_back(')');
        solve(ans,temp,open,close+1,n);
        temp.pop_back();
        }
        
           
    }
    vector<string> generateParenthesis(int n) {
        vector<string>ans;
        string temp="";
        int open=0,close=0;
        solve(ans,temp,open,close,n);
        return ans;
    }
};