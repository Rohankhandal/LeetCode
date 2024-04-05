class Solution {
public:
    string makeGood(string s) {
        stack<char>st;
       int n=s.size();
       st.push(s[0]);
        for(int i=1;i<n;i++)
        {
            if(!st.empty()&& isupper(s[i]) && islower(st.top()) && tolower(s[i])==st.top())
            {
                st.pop();
            }
            else if(!st.empty()&& islower(s[i])&& isupper(st.top()) && s[i]==tolower(st.top()))
            {
                st.pop();
            }
            else
            {
                st.push(s[i]);
            }
        }

        string ans="";
        while(!st.empty())
        {
            ans+=st.top();
            st.pop();
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};