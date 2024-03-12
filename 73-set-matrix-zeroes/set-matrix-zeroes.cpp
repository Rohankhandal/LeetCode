//Optimal Solution
// Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no. of columns in the matrix.
// Reason: In this approach, we are also traversing the entire matrix 2 times and each traversal is taking O(N*M) time complexity.

// Space Complexity: O(1) as we are not using any extra space.
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int m = matrix[0].size();
        bool firstCol = false;
        bool firstRow = false;

        // set markers in first row and first column
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                if (matrix[i][j] == 0) {
                    if (i == 0)
                        firstRow = true;
                    if (j == 0)
                        firstCol = true;

                    matrix[0][j] = 0;
                    matrix[i][0] = 0;
                }
            }
        }
        // replace inner matrix
        for (int i = 1; i < n; i++) {
            for (int j = 1; j < m; j++) {
                if (matrix[i][0] == 0 || matrix[0][j] == 0) {
                    matrix[i][j] = 0;
                }
            }
        }
        // last reamining checks
        if (firstRow) {
            for (int j = 0; j < m; j++) {
                matrix[0][j] = 0;
            }
        }
        if (firstCol) {
            for (int i = 0; i < n; i++) {
                matrix[i][0] = 0;
            }
        }
    }
};




//Best Method
// Time Complexity: O(2*(N*M)), where N = no. of rows in the matrix and M = no.
// of columns in the matrix. Reason: We are traversing the entire matrix 2 times
// and each traversal is taking O(N*M) time complexity.

// Space Complexity: O(N) + O(M), where N = no. of rows in the matrix and M =
// no. of columns in the matrix. Reason: O(N) is for using the row array and
// O(M) is for using the col array. class Solution { public:

//     void setZeroes(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();
//         vector<int>row(n,0); // row array
//         vector<int>col(m,0); // col array

//     // Traverse the matrix:
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (matrix[i][j] == 0) {
//                 // mark ith index of row wih 1:
//                 row[i] = 1;

//                 // mark jth index of col wih 1:
//                 col[j] = 1;
//             }
//         }
//     }

//     // Finally, mark all (i, j) as 0
//     // if row[i] or col[j] is marked with 1.
//     for (int i = 0; i < n; i++) {
//         for (int j = 0; j < m; j++) {
//             if (row[i] || col[j]) {
//                 matrix[i][j] = 0;
//             }
//         }
//     }

//     }
// };