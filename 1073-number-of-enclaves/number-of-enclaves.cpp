class Solution {
public:
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<int>>& board, int i, int j) {
        int n = board.size();
        int m = board[0].size();
        
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == 0) 
            return;

        board[i][j] = 0;  // mark non-flippable 'O'

        for (auto& d : dir) {
            int _i = i + d[0];
            int _j = j + d[1];
            dfs(board, _i, _j);
        }
    }
    int numEnclaves(vector<vector<int>>& grid) {
       int n = grid.size();
        int m = grid[0].size();

      
        for (int j = 0; j < m; j++) {
            if (grid[0][j] == 1) dfs(grid, 0, j);            // Top border
            if (grid[n - 1][j] == 1) dfs(grid, n - 1, j);    // Bottom border
        }
        
        for (int i = 0; i < n; i++) {
            if (grid[i][0] == 1) dfs(grid, i, 0);            // Left border
            if (grid[i][m - 1] == 1) dfs(grid, i, m - 1);    // Right border
        }
        
        int cnt=0;
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if(grid[i][j]==1) cnt++;
            }
        }
        return cnt;
        
    }
};