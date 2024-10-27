// Time Complexity: O(3^(n*m))
// - For each cell, we make 3 recursive calls (right, down, diagonal)
// - At each position, we branch into 3 different paths
// - Height of recursion tree can go up to n*m (in worst case)
// - This leads to 3^(n*m) different recursive calls

// Space Complexity: O(n*m)
// - Due to recursion stack depth which can go up to n*m in worst case
// class Solution {
// public:
//     // Recursive function to find the size of largest square submatrix
//     // i, j: current position in matrix
//     // maxi: reference to store maximum side length found so far
//     int solve(vector<vector<char>>& matrix, int i, int j, int &maxi) {
//         int n = matrix.size();
//         int m = matrix[0].size();

//         // Base case: if we go out of bounds
//         if(i >= n || j >= m) {
//             return 0;
//         }

//         // Recursively check three directions:
//         // 1. Right cell
//         int right = solve(matrix, i, j+1, maxi);
//         // 2. Down cell
//         int down = solve(matrix, i+1, j, maxi);
//         // 3. Diagonal cell (down-right)
//         int diagonal = solve(matrix, i+1, j+1, maxi);

//         // If current cell is '1'
//         if(matrix[i][j] == '1') {
//             // The size of square = 1 + minimum of right, down, and diagonal
//             // We take minimum because we need all 1's to form a square
//             int ans = 1 + min(right, min(down, diagonal));
//             // Update maximum side length found so far
//             maxi = max(ans, maxi);
//             return ans;
//         }
//         else {
//             // If current cell is '0', no square can be formed here
//             return 0;
//         }
//     }

//     // Main function to find area of maximal square
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int i = 0, j = 0;  // Start from top-left corner
//         int maxi = 0;      // To store maximum side length
//         solve(matrix, i, j, maxi);
//         return maxi * maxi;  // Return area (side length squared)
//     }
// };



// Time Complexity: O(n*m)
// - Each cell in matrix is computed only once
// - After first computation, result is stored in dp array
// - Subsequent calls for same cell return stored result
// - We visit each cell exactly once

// Space Complexity: O(n*m)
// - O(n*m) for dp array to store results
// - O(n*m) for recursion stack in worst case
// - Total: O(n*m)
class Solution {
public:
    // Helper function with memoization
    int solve(vector<vector<char>>& matrix, int i, int j, int &maxi, 
              vector<vector<int>>& dp) {
        int n = matrix.size();
        int m = matrix[0].size();

        // Base case: out of bounds
        if(i >= n || j >= m) {
            return 0;
        }

        // If already calculated, return stored result
        if(dp[i][j] != -1) {
            return dp[i][j];
        }

        // Recursive calls with memoization
        int right = solve(matrix, i, j+1, maxi, dp);
        int down = solve(matrix, i+1, j, maxi, dp);
        int diagonal = solve(matrix, i+1, j+1, maxi, dp);

        // Calculate result for current cell
        if(matrix[i][j] == '1') {
            dp[i][j] = 1 + min(right, min(down, diagonal));
            maxi = max(dp[i][j], maxi);
            return dp[i][j];
        }
        else {
            dp[i][j] = 0;
            return 0;
        }
    }
    
    int maximalSquare(vector<vector<char>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        
        // Initialize dp array with -1
        vector<vector<int>> dp(n, vector<int>(m, -1));
        
        int maxi = 0;
        solve(matrix, 0, 0, maxi, dp);
        return maxi * maxi;
    }
};


//T.c:-O(M*N);
//S.C:-O(M*N);
// class Solution {
// public:
//     int maximalSquare(vector<vector<char>>& matrix) {
//         int n = matrix.size();
//         int m = matrix[0].size();
//         int maxi = 0;

//         // Initialize dp array
//         vector<vector<int>> dp(n, vector<int>(m, 0));

//         // Iterate through the matrix
//         for (int i = 0; i < n; i++) {
//             for (int j = 0; j < m; j++) {
//                 // Only proceed if the current cell is '1'
//                 if (matrix[i][j] == '1') {
//                     // Base case for the first row and first column
//                     if (i == 0 || j == 0) {
//                         dp[i][j] = 1; // Single '1' cell contributes to a square of size 1
//                     } else {
//                         // Fill dp table based on minimum of top, left, and top-left diagonal
//                         dp[i][j] = 1 + min({dp[i - 1][j], dp[i][j - 1], dp[i - 1][j - 1]});
//                     }
//                     // Update the maximum square side length found so far
//                     maxi = max(maxi, dp[i][j]);
//                 }
//             }
//         }

//         return maxi * maxi; // Return the area of the largest square
//     }
// };
