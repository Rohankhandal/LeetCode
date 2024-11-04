// class Solution {
// public:
//     string simplifyPath(string path) {
//     stack<string> dirs;
//     stringstream ss(path);
//     string part;

//     // Split path by '/' and process each part
//     while (getline(ss, part, '/')) {
//         if (part == "" || part == ".") {
//             // Skip empty or current directory
//             continue;
//         } else if (part == "..") {
//             // Go up one directory if possible
//             if (!dirs.empty()) {
//                 dirs.pop();
//             }
//         } else {
//             // Push the valid directory name onto the stack
//             dirs.push(part);
//         }
//     }

//     // Construct the simplified path
//     string result;
//     while (!dirs.empty()) {
//         result = "/" + dirs.top() + result;
//         dirs.pop();
//     }

//     // If the result is empty, it means we're at root
//     return result.empty() ? "/" : result;
//     }
// };

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> st;
        int i = 0;
        while (i < path.size()) {
            int start = i;
            int end = i + 1;
            while (end < path.size() && path[end] != '/') {
                ++end;
            }

            string minPath = path.substr(start, end - start);
            i = end;
            cout << minPath << endl; // check what store in stack

            if (minPath == "/" || minPath == "/.")
                continue;

            if (minPath != "/..") {
                st.push(minPath);
            } else if (!st.empty()) {
                st.pop();
            }
        }

        string ans = st.empty() ? "/" : ""; // e.g:- /../
        while (!st.empty()) {
            ans = st.top() + ans;
            st.pop();
        }
        return ans;
    }
};