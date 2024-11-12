class Solution {
public:
    int longestValidParentheses(string s) {
        int n=s.size();
        int maxLen=0;
        stack<int>st;
        st.push(-1);
        for(int i=0;i<n;i++){
            if(s[i]=='(') st.push(i);
            else
            {
                st.pop();   // first pop top element
                if(st.empty())
                {
                    st.push(i);
                }
                else 
                {
                    int len=i-st.top();
                    maxLen=max(maxLen,len);
                }
            }
        }
        return maxLen;
    }
};