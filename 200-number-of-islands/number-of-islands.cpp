//Approach-2 (BFS)
//T.C : O(m*n)
//S.C : O(1)
class Solution {
public:
    vector<pair<int,int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
    
    void bfs(vector<vector<char>>& grid, int i, int j, int n, int m) {
        queue<pair<int,int>> q;
        q.push({i,j});
        grid[i][j] = '$';  // Mark as visited
        
        while (!q.empty()) {
            pair<int,int> p = q.front();
            q.pop();
            
            for (auto &d : dir) {
                int newI = p.first + d.first;
                int newJ = p.second + d.second;
                
                if (newI >= 0 && newI < n && newJ >= 0 && newJ < m && grid[newI][newJ] == '1') {
                    grid[newI][newJ] = '$';  // Mark as visited before pushing to queue
                    q.push({newI, newJ});
                }
            }
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
                    bfs(grid, i, j, n, m);
                    islandCount++;
                }
            }
        }
        
        return islandCount;
    }
};


// DFS
//Approach-1 (DFS)
//T.C : O(m*n)
//S.C : O(1)

// class Solution {
// public:
//     vector<pair<int,int>> dir{{1,0},{0,1},{-1,0},{0,-1}};
    
//     void solve(vector<vector<char>>& grid, int i, int j, int n, int m) {
//         if (i < 0 || i >= n || j < 0 || j >= m || grid[i][j] != '1') {
//         return;
//     }
    
//     grid[i][j] = '$';  // Mark as visited
    
//     for (pair<int,int>&p : dir) {
//         int newI = i + p.first;
//         int newJ = j + p.second;
        
//             solve(grid, newI, newJ, n, m);  
//     }
//     }

//     int numIslands(vector<vector<char>>& grid) {
//         if (grid.empty() || grid[0].empty()) {
//             return 0;
//         }
        
//         int n = grid.size();
//         int m = grid[0].size();
//         int islandCount = 0;
        
//         for (int i = 0; i < n; ++i) {
//             for (int j = 0; j < m; ++j) {
//                 if (grid[i][j] == '1') {
//                     solve(grid, i, j, n, m);
//                     islandCount++;
//                 }
//             }
//         }
        
//         return islandCount;
//     }
// };