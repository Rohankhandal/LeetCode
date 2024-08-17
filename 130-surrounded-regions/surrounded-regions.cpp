class Solution {
public:
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};
    
    void dfs(vector<vector<char>>& board, int i, int j) {
        int n = board.size();
        int m = board[0].size();
        
        if (i < 0 || j < 0 || i >= n || j >= m || board[i][j] == 'X' || board[i][j] == '$') 
            return;

        board[i][j] = '$';  // mark non-flippable 'O'

        for (auto& d : dir) {
            int _i = i + d[0];
            int _j = j + d[1];
            dfs(board, _i, _j);
        }
    }
    
    void solve(vector<vector<char>>& board) {
        int n = board.size();
        int m = board[0].size();

        // Mark all 'O's on the borders and their connected regions
        for (int j = 0; j < m; j++) {
            if (board[0][j] == 'O') dfs(board, 0, j);            // Top border
            if (board[n - 1][j] == 'O') dfs(board, n - 1, j);    // Bottom border
        }
        
        for (int i = 0; i < n; i++) {
            if (board[i][0] == 'O') dfs(board, i, 0);            // Left border
            if (board[i][m - 1] == 'O') dfs(board, i, m - 1);    // Right border
        }
        
        // Replace all remaining 'O's with 'X' and '$' with 'O'
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (board[i][j] == '$') board[i][j] = 'O';  // Restore non-flippable 'O'
                else if (board[i][j] == 'O') board[i][j] = 'X';  // Flip surrounded 'O' to 'X'
            }
        }
    }
};
