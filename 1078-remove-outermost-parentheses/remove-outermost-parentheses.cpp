class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans="";
        stack<char>st;
        for(int i=0;i<s.size();i++)
        {
            char ch=s[i];
            if(ch=='(')
            {
                if(st.size()>0)
                {
                    ans+="(";
                }
                st.push('(');
            }
            else
            {
                if(st.size()>=2)
                {
                    ans+=")";
                }
                st.pop();
            }
        }
        return ans;
    }
};