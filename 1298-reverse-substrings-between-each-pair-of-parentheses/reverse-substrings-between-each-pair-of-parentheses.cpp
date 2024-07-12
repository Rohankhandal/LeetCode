class Solution {
public:
    string reverseParentheses(string s) {
        stack<string> st;
        int n = s.size();
        string ans = "";
        
        for (int i = 0; i < n; i++) {
            if (s[i] == '(') {
                // Push a marker for the beginning of a new segment
                st.push("(");
            } else if (s[i] == ')') {
                // Pop elements until the matching '(' and reverse the segment
                string temp = "";
                while (!st.empty() && st.top() != "(") {
                    temp = st.top() + temp;
                    st.pop();
                }
                // Pop the '('
                if (!st.empty()) {
                    st.pop();
                }
                // Reverse the temp string
                reverse(temp.begin(), temp.end());
                // Push the reversed string back to the stack
                st.push(temp);
            } else {
                // Push the current character as a string
                st.push(string(1, s[i]));
            }
        }
        
        // Construct the final answer
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        
        return ans;
    }
};