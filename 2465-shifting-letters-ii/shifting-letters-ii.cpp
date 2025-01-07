class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> v(n + 1, 0);

        // Apply the shifts to the difference array
        for (auto &q : shifts) {
            int l = q[0];
            int r = q[1];
            int dir = q[2];

            if (dir == 1) {
                v[l]++;
                v[r + 1]--;
            } else {
                v[l]--;
                v[r + 1]++;
            }
        }

        // Compute the prefix sum to get the net shift at each index
        for (int i = 1; i < n; i++) {
            v[i] += v[i - 1];
        }

        // Apply the calculated shifts to the string
        for (int i = 0; i < n; i++) {
            int val = (s[i] - 'a' + v[i]) % 26;
            if (val < 0) {
                val += 26;
            }
            s[i] = 'a' + val;
        }

        return s;
    }
};
