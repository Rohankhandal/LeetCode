class Solution {
public:
    bool check(vector<vector<int>>& grid, int i, int j) {
        // Checking if all numbers are distinct and between 1 and 9
        vector<int> count(10, 0);
        for (int x = i; x < i + 3; ++x) {
            for (int y = j; y < j + 3; ++y) {
                int num = grid[x][y];
                if (num < 1 || num > 9 || count[num]++) {
                    return false;
                }
            }
        }

        // Calculate sum of the first row
        int sum = grid[i][j] + grid[i][j + 1] + grid[i][j + 2];

        // Check rows
        for (int x = i + 1; x < i + 3; ++x) {
            if (grid[x][j] + grid[x][j + 1] + grid[x][j + 2] != sum) {
                return false;
            }
        }

        // Check columns
        for (int y = j; y < j + 3; ++y) {
            if (grid[i][y] + grid[i + 1][y] + grid[i + 2][y] != sum) {
                return false;
            }
        }

        // Check diagonals
        if (grid[i][j] + grid[i + 1][j + 1] + grid[i + 2][j + 2] != sum) {
            return false;
        }
        if (grid[i][j + 2] + grid[i + 1][j + 1] + grid[i + 2][j] != sum) {
            return false;
        }

        return true;
    }

    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        if (n < 3 || m < 3) return 0;

        int ans = 0;
        for (int i = 0; i <= n - 3; ++i) {
            for (int j = 0; j <= m - 3; ++j) {
                if (check(grid, i, j)) {
                    ans++;
                }
            }
        }
        return ans;
    }
};
