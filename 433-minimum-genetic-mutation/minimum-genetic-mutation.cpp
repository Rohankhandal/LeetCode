class Solution {
public:
    int minMutation(string s, string e, vector<string>& bank) {
        int ans = 0;
        unordered_set<string> st(bank.begin(), bank.end());
        
        if (!st.count(e)) return -1; // If the end string is not in the bank, return -1

        queue<string> q;
        q.push(s);
        unordered_set<string> visited;
        visited.insert(s);
        
        vector<char> dir {'A', 'C', 'G', 'T'};

        while (!q.empty()) {
            int sz = q.size();
            for (int i = 0; i < sz; i++) {
                string temp = q.front();
                q.pop();

                if (temp == e) return ans;

                for (int j = 0; j < 8; j++) {
                    char original = temp[j];
                    for (char c : dir) {
                        if (c == original) continue; // Skip if it's the same character
                        temp[j] = c;

                        if (st.count(temp) && !visited.count(temp)) {
                            q.push(temp);
                            visited.insert(temp);
                        }
                    }
                    temp[j] = original; // Restore original character
                }
            }
            ans++;
        }
        return -1;
    }
};
