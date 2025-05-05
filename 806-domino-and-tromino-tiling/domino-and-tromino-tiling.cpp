class Solution {
    const long long mod = 1e9 + 7;
    vector<vector<vector<long long>>> dp;

    long long helper(int i, int top, int bottom) {
        // Base case: all filled
        if (i == 0 && top == 0 && bottom == 0) return 1;
        // Invalid case
        if (i < 0) return 0;
        // Memoization check
        if (dp[i][top][bottom] != -1) return dp[i][top][bottom];

        long long total = 0;

        // No pending cells
        if (top == 0 && bottom == 0) {
            total = (total + helper(i - 1, 0, 0)) % mod;  // Vertical domino
            total = (total + helper(i - 2, 0, 0)) % mod;  // Two horizontal dominoes
            total = (total + helper(i - 1, 1, 0)) % mod;  // Top L-shape
            total = (total + helper(i - 1, 0, 1)) % mod;  // Bottom L-shape
        }

        // Top cell pending
        if (top == 1 && bottom == 0) {
            total = (total + helper(i - 1, 0, 1)) % mod;  // Complete L-shape
            total = (total + helper(i - 2, 0, 0)) % mod;  // Two horizontals
        }

        // Bottom cell pending
        if (top == 0 && bottom == 1) {
            total = (total + helper(i - 1, 1, 0)) % mod;  // Complete L-shape
            total = (total + helper(i - 2, 0, 0)) % mod;  // Two horizontals
        }

        return dp[i][top][bottom] = total;
    }

public:
    int numTilings(int n) {
        // Initialize dp table with -1
        dp = vector<vector<vector<long long>>>(n + 1, vector<vector<long long>>(2, vector<long long>(2, -1)));
        return helper(n, 0, 0);
    }
};
