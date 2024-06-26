class Solution {
public:
    string removeDuplicates(string s) {
        string ans="";
        stack<char> st;
        int n=s.size();
        st.push(s[0]);
        for(int i=1;i<n;i++)
        {
            if(!st.empty() && s[i]==st.top())
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }
        while(!st.empty())
        {
            ans=st.top()+ans;
            st.pop();
        }
        return ans;
    }
};