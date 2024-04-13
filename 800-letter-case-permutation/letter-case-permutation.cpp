class Solution {
public:
    void solve(vector<string>&ans,string temp,string s,int i)
    {
        if(i>=s.size())
        {
            ans.push_back(temp);
            return ;
        }
        if(isalpha(s[i]))
        {
            //not_take(means not change in capital letter)
           
            solve(ans,temp+s[i],s,i+1);
            

            //take
            if(s[i]>='a' && s[i]<='z') temp.push_back(s[i]-32);
            if(s[i]>='A' && s[i]<='Z') temp.push_back(s[i]+32);
            solve(ans,temp,s,i+1);
            temp.pop_back();
        }
        else
        {
            temp.push_back(s[i]);
            solve(ans,temp,s,i+1);
        }
    }
    vector<string> letterCasePermutation(string s) {
        string temp="";
        int i=0;
        vector<string>ans;
        solve(ans,temp,s,i);
        return ans;
    }
};