class Solution {
public:
   
    int solve(vector<vector<int>>&board)
    {
       string target = "123450"; // Goal state
    string start = "";
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            start += to_string(board[i][j]);
        }
    }
    
    vector<vector<int>> dir{{-1, 0}, {1, 0}, {0, 1}, {0, -1}}; // Movement directions
    queue<pair<string, int>> q; // {current state, number of moves}
    unordered_set<string> visited; // To track visited states
    
    q.push({start, 0});
    visited.insert(start);
    
    while (!q.empty()) {
        auto [curr, moves] = q.front();
        q.pop();
        
        if (curr == target) return moves; // Found the solution
        
        int zeroPos = curr.find('0'); // Find position of '0'
        int row = zeroPos / 3; // Convert 1D index to 2D
        int col = zeroPos % 3;
        
        for (auto& d : dir) {
            int newRow = row + d[0];
            int newCol = col + d[1];
            
            // Check if the new position is within bounds
            if (newRow >= 0 && newRow < 2 && newCol >= 0 && newCol < 3) {
                int newZeroPos = newRow * 3 + newCol; // Convert back to 1D index
                string next = curr;
                swap(next[zeroPos], next[newZeroPos]); // Swap '0' with the new position
                
                if (visited.find(next) == visited.end()) {
                    q.push({next, moves + 1});
                    visited.insert(next);
                }
            }
        }
    }
    
    return -1; // If no solution found

    }
    int slidingPuzzle(vector<vector<int>>& board) {
        return solve(board);
    }
};