// Approach-1: Using Dijkstra's Algorithm
class Solution {
public:
    typedef pair<int, pair<int, int>> P; // A custom type for priority queue elements: (effort, (x, y))

    // Directions array for moving up, down, left, and right
    vector<vector<int>> dirs = {
        {-1, 0}, // Up
        {0, -1}, // Left
        {0, 1},  // Right
        {1, 0}   // Down
    };

    int minimumEffortPath(vector<vector<int>>& heights) {
        int m = heights.size();
        int n = heights[0].size();
        
        // Lambda function to check if a cell is within bounds
        auto isSafe = [&](int x, int y) {
            return x >= 0 && x < m && y >= 0 && y < n;
        };
        
        // Initialize result array with maximum possible effort (INT_MAX)
        vector<vector<int>> result(m, vector<int>(n, INT_MAX));
        
        // Min-heap priority queue to process cells by minimum effort
        priority_queue<P, vector<P>, greater<P>> pq;
        
        // Start from the top-left corner (0,0) with initial effort 0
        pq.push({0, {0, 0}});
        result[0][0] = 0;
  
        // Dijkstra's algorithm to find the minimum effort path
        while(!pq.empty()) {
            int diff = pq.top().first; // Current minimum effort
            auto node = pq.top().second; // Current cell (x, y)
            pq.pop();

            int x = node.first;
            int y = node.second;
            
            // Early exit: if we reach the bottom-right corner, return the effort
            if (x == m - 1 && y == n - 1) {
                return diff;
            }
            
            // Explore all four directions
            for (auto dir : dirs) {
                int x_ = x + dir[0];
                int y_ = y + dir[1];

                // Check if the next cell is within bounds
                if (isSafe(x_, y_)) {
                    // Calculate the effort to move to the next cell
                    int newDiff = max(diff, abs(heights[x][y] - heights[x_][y_]));
                    
                    // Update the result if a smaller effort is found
                    if (result[x_][y_] > newDiff) {
                        result[x_][y_] = newDiff;
                        pq.push({result[x_][y_], {x_, y_}});
                    }
                }
            }
        }
   
        // Return the minimum effort required to reach the bottom-right corner
        return result[m-1][n-1];
    }
};
