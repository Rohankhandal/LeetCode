class Solution {
public:
    bool isValid(string s) {
        if (s.empty() || s[0] != 'a') return false;  // String must start with 'a' for a valid "abc" sequence

        stack<char> st;
        for (char ch : s) {
            if (ch == 'a') {
                st.push(ch);  // Start of a new "abc" sequence
            }
            else if (ch == 'b') {
                if (!st.empty() && st.top() == 'a') {
                    st.push(ch);  // Valid 'b' follows an 'a'
                } else {
                    return false;  // Invalid sequence if 'b' does not follow 'a'
                }
            }
            else if (ch == 'c') {
                if (!st.empty() && st.top() == 'b') {
                    st.pop();  // Pop 'b' as part of "abc"
                    if (!st.empty() && st.top() == 'a') {
                        st.pop();  // Pop 'a' to complete the "abc" sequence
                    } else {
                        return false;  // Invalid sequence if 'a' is missing
                    }
                } else {
                    return false;  // Invalid sequence if 'c' does not follow 'b'
                }
            }
            else {
                return false;  // Invalid character detected (only 'a', 'b', 'c' are allowed)
            }
        }
        return st.empty();  // Stack must be empty if all "abc" sequences are valid
    }
};



// T.c:-O(N^2)
// class Solution {
// public:
//     bool isValid(string s) {
//         int idx = s.find("abc");
//         while (idx != string::npos) {
//             s.replace(idx, 3, "");  // Remove "abc" at the found position
//             idx = s.find("abc");     // Find next occurrence of "abc"
//         }
//         return s.empty(); // If all "abc" patterns were removed, s should be empty
//     }
// };
