class Solution {
public:
    bool isValid(vector<vector<int>>& grid2, int i, int j) {
        int n = grid2.size();
        int m = grid2[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || grid2[i][j] == 0) 
            return false;
        return true;
    }

    void isSubIsland(vector<vector<int>>& grid1, vector<vector<int>>& grid2, vector<vector<bool>>& visited, int i, int j, bool& flag) {
        // If the current cell in grid2 doesn't match grid1, it's not a sub-island
        if (grid2[i][j] != grid1[i][j]) {
            flag = false;  //not sub-island , but mark this sub-island , so that we don't use in future
        }

        visited[i][j] = true;

        vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        // Explore all 4 possible directions (up, down, right, left)
        for (auto &d : dir) {
            int newI = d[0] + i;
            int newJ = d[1] + j;

            if (isValid(grid2, newI, newJ) && !visited[newI][newJ]) {
                isSubIsland(grid1, grid2, visited, newI, newJ, flag);
            }
        }
    }

    int countSubIslands(vector<vector<int>>& grid1, vector<vector<int>>& grid2) {
        int n = grid1.size();
        int m = grid1[0].size();

        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int ans = 0;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (grid2[i][j] == 1 && !visited[i][j]) {
                    bool flag = true;  // Initialize the flag as true
                    isSubIsland(grid1, grid2, visited, i, j, flag);
                    if (flag) {
                        ans++;  // Increment the count if the flag is still true
                    }
                }
            }
        }

        return ans;
    }
};
