#include <vector>
using namespace std;

class Solution {
public:
    vector<int> findPeakGrid(vector<vector<int>>& mat) {
        int rows = mat.size();
        int cols = mat[0].size();
        int left = 0, right = cols - 1;

        while (left <= right) {
            int midCol = left + (right - left) / 2;
            int maxRow = 0;

            // Find the row with the maximum element in the middle column
            for (int i = 0; i < rows; i++) {
                if (mat[i][midCol] > mat[maxRow][midCol]) {
                    maxRow = i;
                }
            }

            // Check neighbors to determine the direction
            int leftNeighbor = (midCol > 0) ? mat[maxRow][midCol - 1] : -1;
            int rightNeighbor = (midCol < cols - 1) ? mat[maxRow][midCol + 1] : -1;

            if (mat[maxRow][midCol] > leftNeighbor && mat[maxRow][midCol] > rightNeighbor) {
                return {maxRow, midCol}; // Found the peak
            } else if (mat[maxRow][midCol] < leftNeighbor) {
                right = midCol - 1; // Search left
            } else {
                left = midCol + 1; // Search right
            }
        }
        return {-1, -1}; // Shouldn't reach here
    }
};
