
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int r = matrix.size();
        int c = matrix[0].size();
        vector<int>row(r,-1);
        vector<int>col(c,-1);
        for(int i=0;i<r;i++ )
        {
            for(int j=0;j<c;j++)
            {
                if(matrix[i][j]==0)
                {
                    row[i]=1;
                    break;
                }
            }
        }
        for(int j=0;j<c;j++ )
        {
            for(int i=0;i<r;i++)
            {
                if(matrix[i][j]==0)
                {
                    col[j]=1;
                    break;
                }
            }
        }
        //mark elements
        for(int i=0;i<r;i++)
        {
            for(int j=0;j<c;j++)
            {
                if(row[i]==1 || col[j]==1)
                {
                    matrix[i][j]=0;
                }
            }
        }
        return ;
    }
};



// //Fail if Matrix [[-1],[2],[3]] then OUTPUT:-[[-1],[2],[3]] BUT ACCORDING TO CODE [[0],[2],[3]]
// class Solution {
// public:
//     void setZeroes(vector<vector<int>>& matrix) {
//         int r = matrix.size();
//         int c = matrix[0].size();
//         for (int i = 0; i < r; i++) {
//             for (int j = 0; j < c; j++) {
//                 if (matrix[i][j] == 0) {
//                     // left marking as -1
//                     for (int k = j; k >= 0; k--) {
//                         if (matrix[i][k] != 0)
//                             matrix[i][k] = -1;
//                     }
//                     // right marking as -1
//                     for (int k = j; k < c; k++) {
//                         if (matrix[i][k] != 0)
//                             matrix[i][k] = -1;
//                     }
//                     // up marking as -1
//                     for (int k = i; k >= 0; k--) {
//                         if (matrix[k][j] != 0)
//                             matrix[k][j] = -1;
//                     }
//                     // down marking as -1
//                     for (int k = i; k < r; k++) {
//                         if (matrix[k][j] != 0)
//                             matrix[k][j] = -1;
//                     }
//                 }
//             }
//         }

//         // print
//         for (int i = 0; i < r; i++) {
//             for (int j = 0; j < c; j++) {
//                 if (matrix[i][j] == -1)
//                     matrix[i][j] = 0;
//             }
//         }
//     }
// };