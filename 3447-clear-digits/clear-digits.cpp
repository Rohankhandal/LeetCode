class Solution {
public:
    string clearDigits(string s) {
        string ans="";
        stack<char>st;
        for(auto &ch:s){
            if(isdigit(ch))
            {
                if(!st.empty())
                {
                    st.pop();
                }
            }
            else st.push(ch);
        }
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};