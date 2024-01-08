class Solution {
public:
    string removeOuterParentheses(string s) {
        string temp="";
        string ans="";
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(ch=='(')
            {
                temp+=ch;
                if(temp.size()>=2)
                {
                  ans+=ch;
                  
                }
            }
            else if(ch==')' && temp.size()!=1)
            {
                ans+=ch;
                temp.pop_back();
            }
            else 
            {
                temp.pop_back();
            }
        }
        return ans;
    }
};