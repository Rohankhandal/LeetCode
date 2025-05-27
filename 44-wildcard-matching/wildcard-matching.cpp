class Solution {
public:
    vector<vector<int>> dp;

    bool f(string& s, string& p, int i, int j) {
        int n = s.size(), m = p.size();

        // Base Cases
        if (i >= n && j >= m) return true;              // both strings exhausted
        if (j >= m) return false;                       // pattern exhausted but s not
        if (i >= n) {
            // s is done, but pattern has remaining chars
            // only match if all remaining pattern chars are '*'
            for (int k = j; k < m; ++k)
                if (p[k] != '*') return false;
            return true;
        }

        if (dp[i][j] != -1) return dp[i][j];

        bool ans = false;

        if (p[j] == s[i] || p[j] == '?') {
            ans = f(s, p, i + 1, j + 1);
        } else if (p[j] == '*') {
            // '*' can match empty or one character (and continue matching)
            ans = f(s, p, i, j + 1) || f(s, p, i + 1, j);
        } else {
            ans = false;
        }

        return dp[i][j] = ans;
    }

    bool fTab(string s,string p)
    {
        int n = s.size(), m = p.size();

        // dp[i][j] means: does s[i:] match p[j:]
        vector<vector<bool>> dp(n + 1, vector<bool>(m + 1, false));

        // Base Case: empty string matches empty pattern
        dp[n][m] = true;

        // Fill last row: when s is empty (i == n)
        for (int j = m - 1; j >= 0; --j) {
            if (p[j] == '*')
                dp[n][j] = true;
            else
                break; // no point continuing if current isn't '*'            //IMP POINT
        }

        // Fill the table from bottom up
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (p[j] == s[i] || p[j] == '?') {
                    dp[i][j] = dp[i + 1][j + 1];
                } else if (p[j] == '*') {
                    dp[i][j] = dp[i + 1][j]   // '*' matches one char
                             || dp[i][j + 1]; // '*' matches empty
                } else {
                    dp[i][j] = false;
                }
            }
        }

        return dp[0][0];
    }


    int fSpace(string s,string p)
    {
        int n = s.size(), m = p.size();

        // dp[j] represents dp[i+1][j]
        vector<bool> prev(m + 1, false), curr(m + 1, false);

        // Base case: empty string and empty pattern match
        prev[m] = true;

        // Fill last row (i = n): when s is exhausted
        for (int j = m - 1; j >= 0; --j) {
            if (p[j] == '*')
                prev[j] = true;
            else
                break;
        }

        // Process from i = n-1 to 0
        for (int i = n - 1; i >= 0; --i) {
            for (int j = m - 1; j >= 0; --j) {
                if (p[j] == s[i] || p[j] == '?') {
                    curr[j] = prev[j + 1];
                } else if (p[j] == '*') {
                    curr[j] = prev[j] || curr[j + 1];
                } else {
                    curr[j] = false;
                }
            }

            prev = curr;
        }

        return prev[0]; // result for dp[0][0]
    }
    bool isMatch(string s, string p) {
        // int n = s.size(), m = p.size();
        // dp.assign(n + 1, vector<int>(m + 1, -1));
        // return f(s, p, 0, 0);
        // return fTab(s,p);
        return fSpace(s,p);
    }
};
