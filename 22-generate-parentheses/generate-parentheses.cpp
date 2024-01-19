class Solution {
public:

void generate(vector<string>&ans,string output,int open,int close)
{
    if(open==0&&close==0)
    {
        ans.push_back(output);
        return ;
    }
    if(open>0)
    {
        output.push_back('(');
        generate(ans,output,open-1,close);
        //backtracking
        output.pop_back();
    }
    if(close>open)
    {
        output.push_back(')');
        generate(ans,output,open,close-1);
        //backtracking
        output.pop_back();
    }
}

    vector<string> generateParenthesis(int n) {
        int open=n;
        int close=n;
        vector<string>ans;
        string output="";
        generate(ans,output,open,close);
        return ans;
    }
};