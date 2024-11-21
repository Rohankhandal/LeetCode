class Solution {
public:
    void dfs(int i, int j, vector<vector<int>>& matrix, int m, int n) {

        // Directions for up, down, left, right
        vector<vector<int>> directions{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

        for (auto& dir : directions) {
            int newI = i + dir[0];
            int newJ = j + dir[1];
            // Continue marking in the current direction until hitting a wall or boundary
            while (newI >= 0 && newJ >= 0 && newI < m && newJ < n && matrix[newI][newJ] != -1 && matrix[newI][newJ] != 1) {
                matrix[newI][newJ] = 2; // Mark as guarded
                newI += dir[0];
                newJ += dir[1];
            }
        }
    }
    int countUnguarded(int m, int n, vector<vector<int>>& guards,
                       vector<vector<int>>& walls) {
        vector<vector<int>> matrix(
            m, vector<int>(n, 0)); // Initialize grid with 0 (unguarded cells)

        // Mark guards with 1 and walls with -1
        for (auto& guard : guards) {
            matrix[guard[0]][guard[1]] = 1;
        }
        for (auto& wall : walls) {
            matrix[wall[0]][wall[1]] = -1;
        }

        // Perform DFS for all guards to mark guarded cells
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 1) {
                    dfs(i, j, matrix, m, n);
                }
            }
        }

        // Count unguarded cells (cells with value 0)
        int unguardedCount = 0;
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (matrix[i][j] == 0) {
                    unguardedCount++;
                }
            }
        }

        return unguardedCount;
    }
};