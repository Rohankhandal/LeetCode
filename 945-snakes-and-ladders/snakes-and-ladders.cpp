class Solution {
public:
    int n;
    
    // Converts the 1D position s into the 2D coordinates (row, col) on the board
    pair<int, int> getCoord(int s) {
        int row = n - 1 - (s - 1) / n;
        int col = (s - 1) % n;
        // Adjust for the zigzag pattern
        if ((n % 2 == 1 && row % 2 == 1) || (n % 2 == 0 && row % 2 == 0)) {
            col = n - 1 - col;
        }
        return make_pair(row, col);
    }
    
    int snakesAndLadders(vector<vector<int>>& board) {
        n = board.size();
        int steps = 0;
        queue<int> que;
        vector<bool> visited(n * n + 1, false); // 1D vector to track visited squares
        visited[1] = true;
        que.push(1);
        
        while (!que.empty()) {
            int N = que.size();
            while (N--) {
                int x = que.front();
                que.pop();
                
                if (x == n * n) // Reached the last square
                    return steps;

                for (int k = 1; k <= 6; k++) {
                    if (x + k > n * n) // Beyond the last square
                        break;
                    
                    int nextPos = x + k;
                    pair<int, int> coord = getCoord(nextPos);
                    int r = coord.first;
                    int c = coord.second;
                    
                    if (visited[nextPos])
                        continue;

                    visited[nextPos] = true;
                    
                    // If no ladder/snake at the current position, move normally
                    if (board[r][c] == -1) {
                        que.push(nextPos);
                    } else {
                        // Move to the destination of the ladder/snake
                        que.push(board[r][c]);
                    }
                }
            }
            steps++;
        }
        
        return -1; // If no solution found
    }
};
