// Give TLE

// class Solution {
// public:
//     // Depth-First Search to find the shortest path in the grid
//     int bfs(vector<vector<int>>& grid, int i, int j) {
//         int n = grid.size();
//         int m = grid[0].size();

//         // If the bottom-right corner is reached and it's open, return 1
//         if(i == n - 1 && j == m - 1 && grid[i][j] == 0) return 1;

//         // If out of bounds or hitting an obstacle, return INT_MAX to indicate no valid path
//         if(i < 0 || i >= n || j < 0 || j >= m || grid[i][j] == 1) return INT_MAX;

//         // Mark the current cell as visited
//         grid[i][j] = 1;

//         // Define the 8 possible directions (up, down, left, right, and diagonals)
//         vector<vector<int>> dir{{-1,0}, {1,0}, {0,1}, {0,-1}, {-1,-1}, {1,-1}, {-1,1}, {1,1}};

//         int ans = INT_MAX;

//         // Explore all 8 directions
//         for(auto &d : dir) {
//             int newI = i + d[0];
//             int newJ = j + d[1];

//             // Recursively call bfs for the new position
//             int res = bfs(grid, newI, newJ);
//             if(res != INT_MAX) {
//                 ans = min(ans, 1 + res);  // Update the shortest path length
//             }
//         }

//         // Unmark the current cell before backtracking
//         grid[i][j] = 0;

//         return ans;
//     }

//     // Function to find the shortest path in a binary matrix
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();
//         int m = grid[0].size();

//         // If the starting cell is blocked, return -1
//         if(grid[0][0] == 1) return -1;

//         // Call the dfs function to find the shortest path
//         int ans = bfs(grid, 0, 0);

//         // If a valid path is found, return its length; otherwise, return -1
//         return ans != INT_MAX ? ans : -1;
//     }
// };


// To optimize the code, we should switch from a DFS-based approach to a BFS-based approach. BFS is more efficient for finding the shortest path in an unweighted grid like this, as it explores all possible paths level by level, ensuring that the first time it reaches the target cell, it has found the shortest path.
// class Solution {
// public:
//     int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
//         int n = grid.size();
//         if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

//         vector<vector<int>> directions{{-1,0}, {1,0}, {0,1}, {0,-1}, {-1,-1}, {1,-1}, {-1,1}, {1,1}};
//         queue<pair<int, int>> q;
//         q.push({0, 0});
//         grid[0][0] = 1;  // Mark the starting cell as visited by setting it to 1

//         int pathLength = 1;

//         while (!q.empty()) {
//             int size = q.size();

//             for (int i = 0; i < size; ++i) {
//                 auto [x, y] = q.front();
//                 q.pop();

//                 // If we have reached the bottom-right corner, return the path length
//                 if (x == n - 1 && y == n - 1) return pathLength;

//                 // Explore all 8 possible directions
//                 for (auto& dir : directions) {
//                     int newX = x + dir[0];
//                     int newY = y + dir[1];

//                     // Check if the new position is within bounds and not visited
//                     if (newX >= 0 && newX < n && newY >= 0 && newY < n && grid[newX][newY] == 0) {
//                         q.push({newX, newY});
//                         grid[newX][newY] = 1;  // Mark the cell as visited
//                     }
//                 }
//             }
//             ++pathLength;  // Increment path length after exploring all cells at the current level
//         }

//         // If we exit the loop, there is no valid path
//         return -1;
//     }
// };



//Using Dijkstra
class Solution {
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        int n = grid.size();
        if (grid[0][0] == 1 || grid[n-1][n-1] == 1) return -1;

        vector<vector<int>>dis(n,vector<int>(n,INT_MAX));
        vector<vector<int>> directions{{-1,0}, {1,0}, {0,1}, {0,-1}, {-1,-1}, {1,-1}, {-1,1}, {1,1}};

        auto isSafe=[&grid,&n](int x,int y)
        {
            if(x<0 || x>=n || y<0 || y>=n || grid[x][y]==1) return false;

            return true;
        };
        dis[0][0]=0;
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        pq.push({0,{0,0}});

        while(!pq.empty())
        {

            auto front=pq.top();
            pq.pop();
            int d=front.first;
            int x=front.second.first;
            int y=front.second.second;

            for(auto &dir:directions)
            {
                int x_=dir[0]+x;
                int y_=dir[1]+y;

                if(isSafe(x_,y_))
                {
                    if(d+1<dis[x_][y_])
                    {
                        dis[x_][y_]=d+1;
                        pq.push({dis[x_][y_],{x_,y_}});
                    }
                }
            }
            
        }
        return dis[n-1][n-1]==INT_MAX?-1:dis[n-1][n-1]+1;
        
    }
};