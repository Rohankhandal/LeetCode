class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int rows = box.size();
    int cols = box[0].size();

    // Create a new rotated grid with flipped dimensions
    vector<vector<char>> rotated(cols, vector<char>(rows, '.'));

    // Perform rotation and gravity effect simultaneously
    for (int i = 0; i < rows; ++i) {
        int empty = cols - 1; // Tracks the position to place '*'
        for (int j = cols - 1; j >= 0; --j) {
            if (box[i][j] == '*') {
                rotated[j][rows - 1 - i] = '*'; // Rotate '*'
                empty = j - 1;                  // Reset empty after '*'
            } else if (box[i][j] == '#') {
                rotated[empty][rows - 1 - i] = '#'; // Drop '#' to the lowest valid position
                empty--;                            // Update empty for next stone
            }
        }
    }

    return rotated;
    }
};