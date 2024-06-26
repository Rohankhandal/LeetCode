class Solution {
public:
    vector<pair<int,int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
    
    void solve(vector<vector<char>>& grid, int i, int j, int n, int m) {
        if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1') {
        return;
    }
    
    grid[i][j] = '$';  // Mark as visited
    
    for (pair<int,int>&p : dir) {
        int newI = i + p.first;
        int newJ = j + p.second;
        
            solve(grid, newI, newJ, n, m);  
    }
    }

    int numIslands(vector<vector<char>>& grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        
        int n = grid.size();
        int m = grid[0].size();
        int islandCount = 0;
        
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < m; ++j) {
                if (grid[i][j] == '1') {
                    solve(grid, i, j, n, m);
                    islandCount++;
                }
            }
        }
        
        return islandCount;
    }
};
