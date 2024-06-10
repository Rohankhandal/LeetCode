class Solution {
public:
    string clearDigits(string s) {
        stack<char>st;
        int n=s.size();
        for(int i=0;i<n;i++)
        {
            if(!isdigit(s[i]))
            {
                st.push(s[i]);
            }
            else
            {
                if(!st.empty())
                 st.pop();
            }
        }
        string ans;
        while(!st.empty())
        {
            ans.push_back(st.top());
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};