// class Solution {
// public:
//     bool isValid(vector<string>&board,int row,int col)
//     {
//         //upward
//         for(int i=row;i>=0;i--)
//         {
//             if(board[i][col]=='Q') return false;
//         }
        

//         //check left diagonal upwards
//         for(int i = row, j = col; i>=0 && j >= 0; i--, j--) {
//             if(board[i][j] == 'Q')
//                 return false;
//         }
        
//         //check right diagonal upwards
//         for(int i = row, j = col; i>=0 && j<board.size(); i--, j++) {
//             if(board[i][j] == 'Q')
//                 return false;
//         }

//         return true;
//     }
//     void solve( vector<vector<string>>&ans,int n,vector<string>&board,int row)
//     {
//         if(row>=n)
//         {
//             ans.push_back(board);
//             return ;
//         }


//         for(int col=0;col<n;col++)
//         {
//             if(isValid(board,row,col))
//             {
//                 board[row][col]='Q';
//                 solve(ans,n,board,row+1);
//                 board[row][col]='.';
//             }
//         }
        
//     }
//     vector<vector<string>> solveNQueens(int n) {
//         vector<vector<string>>ans;
//         vector<string>board(n,string(n,'.'));
//         int row=0;
//         solve(ans,n,board,row);

//         return ans;
//     }
// };



//still improvement is possible (again and again check for upward, upward diagonal , upward antidiagonal)
class Solution {
public:
   
    void solve(vector<vector<string>>&ans,int n,vector<string>&board,int row, unordered_set<int>&cols, unordered_set<int>&diags, unordered_set<int>&antiDiags)
    {
        if(row>=n)
        {
            ans.push_back(board);
            return ;
        }


        for(int col=0;col<n;col++)
        {
            int diag_id       = row-col;
            int anti_diag_id  = row+col;
            
            /*
                If the col, or diagonal or anti_diaonal
                are used, means one of them has a Queen placed
                already which can attack, so look for other column
            */
            if(cols.find(col) != cols.end() ||
              diags.find(diag_id) != diags.end() ||
              antiDiags.find(anti_diag_id) != antiDiags.end())
                continue;
            
            cols.insert(col);
            diags.insert(diag_id);
            antiDiags.insert(anti_diag_id);
            board[row][col] = 'Q';
            
            
            solve(ans,n,board, row+1, cols, diags, antiDiags);

            cols.erase(col);
            diags.erase(diag_id);
            antiDiags.erase(anti_diag_id);

            board[row][col] = '.';
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
         unordered_set<int> cols;
        unordered_set<int> diags;
        unordered_set<int> antiDiags;
        int row=0;
        solve(ans,n,board,row,cols,diags,antiDiags);

        return ans;
    }
};

