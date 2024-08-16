class Solution {
public:
    // Directions for moving up, down, right, and left
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}};

    // Depth-First Search (DFS) to mark connected regions
    void dfs(vector<vector<int>>& arr, int i, int j) {
        int n = arr.size();
        int m = arr[0].size();
        
        // Base case: if out of bounds or already visited, return
        if (i < 0 || j < 0 || i >= n || j >= m || arr[i][j] == 1) {
            return;
        }

        // Mark the current cell as visited
        arr[i][j] = 1;

        // Explore all four directions
        for (auto &d : dir) {
            int _i = i + d[0];
            int _j = j + d[1];
            dfs(arr, _i, _j);
        }
    }

    // Function to count the number of regions formed by slashes
    int regionsBySlashes(vector<string>& grid) {
        int n = grid.size();
        
        // Create a 3x3 expanded grid initialized with 0
        vector<vector<int>> arr(n * 3, vector<int>(n * 3, 0));

        // Fill the expanded grid based on slashes in the original grid
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (grid[i][j] == '/') {
                    // Mark the cells corresponding to '/' in the expanded grid
                    arr[i * 3][j * 3 + 2] = 1;
                    arr[i * 3 + 1][j * 3 + 1] = 1;
                    arr[i * 3 + 2][j * 3] = 1;
                } else if (grid[i][j] == '\\') {
                    // Mark the cells corresponding to '\\' in the expanded grid
                    arr[i * 3][j * 3] = 1;
                    arr[i * 3 + 1][j * 3 + 1] = 1;
                    arr[i * 3 + 2][j * 3 + 2] = 1;
                }
            }
        }

        int ans = 0;

        // Perform DFS on each cell in the expanded grid
        for (int i = 0; i < arr.size(); i++) {
            for (int j = 0; j < arr[i].size(); j++) {
                if (arr[i][j] == 0) {
                    // Found an unvisited region, perform DFS to mark it
                    dfs(arr, i, j);
                    ans++; // Increment the region count
                }
            }
        }

        return ans; // Return the total number of regions
    }
};
