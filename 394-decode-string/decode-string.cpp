class Solution {
public:
    string decodeString(string s) {
        stack<char> st;
        int n = s.size();

        for (int i = 0; i < n; i++) {
            char ch = s[i];
            if (ch == ']') {
                string temp = "";

                while (!st.empty() && st.top() != '[') {
                    temp = st.top() + temp;
                    st.pop();
                }

                st.pop();

                string numStr = "";
                while (!st.empty() && isdigit(st.top())) {
                    numStr = st.top() + numStr;  // Collect digits in reverse
                    st.pop();
                }

                int rep = stoi(numStr);

                string d = "";
                for (int j = 0; j < rep; j++) {
                    d += temp;
                }

                for (char it : d) {
                    st.push(it);
                }
            } else {
                st.push(ch);
            }
        }

        string ans = "";
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }

        return ans;
    }
};

