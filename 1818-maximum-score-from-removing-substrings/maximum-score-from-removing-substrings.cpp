class Solution {
public:
    int maximumGain(string s, int x, int y) {
        int n = s.size();
        string first = (x > y) ? "ab" : "ba";
        string second = (x > y) ? "ba" : "ab";
        int fhigh = (x > y) ? x : y;
        int shigh = (x > y) ? y : x;
        int ans = 0;

        stack<char> st;
        // Process the string to maximize the removal of first pattern
        for (int i = 0; i < n; ++i) {
            if (!st.empty() && st.top() == first[0] && s[i] == first[1]) {
                st.pop();
                ans += fhigh;
            } else {
                st.push(s[i]);
            }
        }

        // Now process the remaining string to maximize the removal of second pattern
        string temp;
        while (!st.empty()) {
            temp.push_back(st.top());
            st.pop();
        }
        reverse(temp.begin(), temp.end());

        for (int i = 0; i < temp.size(); ++i) {
            if (!st.empty() && st.top() == second[0] && temp[i] == second[1]) {
                st.pop();
                ans += shigh;
            } else {
                st.push(temp[i]);
            }
        }

        return ans;
    }
};
