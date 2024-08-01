class Solution {
public:
    bool isValid(vector<string>&board,int row,int col)
    {
        //upward
        for(int i=row;i>=0;i--)
        {
            if(board[i][col]=='Q') return false;
        }
        

        //check left diagonal upwards
        for(int i = row, j = col; i>=0 && j >= 0; i--, j--) {
            if(board[i][j] == 'Q')
                return false;
        }
        
        //check right diagonal upwards
        for(int i = row, j = col; i>=0 && j<board.size(); i--, j++) {
            if(board[i][j] == 'Q')
                return false;
        }

        return true;
    }
    void solve( vector<vector<string>>&ans,int n,vector<string>&board,int row)
    {
        if(row>=n)
        {
            ans.push_back(board);
            return ;
        }


        for(int col=0;col<n;col++)
        {
            if(isValid(board,row,col))
            {
                board[row][col]='Q';
                solve(ans,n,board,row+1);
                board[row][col]='.';
            }
        }
        
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>>ans;
        vector<string>board(n,string(n,'.'));
        int row=0;
        solve(ans,n,board,row);

        return ans;
    }
};