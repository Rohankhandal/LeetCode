class Solution {
public:
    bool solve(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>>& memo) {
        // If we have reached the end of s3
        if (k == s3.size()) return true;

        // If this subproblem has been solved before, return the stored result
        if (memo[i][j] != -1) return memo[i][j];

        // If s1 is exhausted, check if remaining s2 matches the rest of s3
        if (i >= s1.size()) {
            while (j < s2.size()) {
                if (s2[j] != s3[k]) return memo[i][j] = false;
                j++; k++;
            }
            return memo[i][j] = (k == s3.size());
        }

        // If s2 is exhausted, check if remaining s1 matches the rest of s3
        if (j >= s2.size()) {
            while (i < s1.size()) {
                if (s1[i] != s3[k]) return memo[i][j] = false;
                i++; k++;
            }
            return memo[i][j] = (k == s3.size());
        }

        // Explore the possibility of taking the current character from s1
        bool op1 = false;
        if (s1[i] == s3[k]) {
            op1 = solve(s1, s2, s3, i + 1, j, k + 1, memo);
        }

        // Explore the possibility of taking the current character from s2
        bool op2 = false;
        if (s2[j] == s3[k]) {
            op2 = solve(s1, s2, s3, i, j + 1, k + 1, memo);
        }

        // Store the result in the memoization table and return it
        return memo[i][j] = (op1 || op2);
    }

    bool isInterleave(string s1, string s2, string s3) {
        int n = s1.size();
        int m = s2.size();
        int size = s3.size();

        // If the combined lengths of s1 and s2 don't match the length of s3, return false
        if (n + m != size) return false;

        // Initialize a memoization table with -1 (indicating unsolved subproblems)
        vector<vector<int>> memo(n + 1, vector<int>(m + 1, -1));

        // Start the recursive function from the beginning of all strings
        return solve(s1, s2, s3, 0, 0, 0, memo);
    }
};
