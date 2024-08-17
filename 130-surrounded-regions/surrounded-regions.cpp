// input=
// [["O","X","X","O","X"],
// ["X","O","O","X","O"],
// ["X","O","X","O","X"],
// ["O","X","O","O","O"],
// ["X","X","O","X","O"]]

// expect =
// [["O","X","X","O","X"],
// ["X","X","X","X","O"],
// ["X","X","X","O","X"],
// ["O","X","O","O","O"],
// ["X","X","O","X","O"]]

// since board[2][3] does not on the boarder and does not connect to anything on the boder, it suppose to flip to "X" ,right? why it stay the same?
class Solution {
public:
     vector<vector<int>>dir{{-1,0},{1,0},{0,1},{0,-1}};
    void dfs(vector<vector<char>>& board,int i,int j)
    {
        int n=board.size();
        int m=board[0].size();

        if(i<0 || j<0 || i>=n || j>=m || board[i][j]=='X' || board[i][j]=='$') return ;

        board[i][j]='$';  //mark


        for(auto &d:dir)
        {
            int _i= i+d[0];
            int _j= j+d[1];

            dfs(board,_i,_j);
        }

    }
    void solve(vector<vector<char>>& board) {
        int n=board.size();
        int m=board[0].size();
        for(int j=0;j<m;j++)  //first row traverse
        {
           if(board[0][j]=='O') dfs(board,0,j);
        }

        for(int i=0;i<n;i++)  //first col traverse
        {
           if(board[i][0]=='O') dfs(board,i,0);
        }

        for(int i=0;i<n;i++)  //last col traverse
        {
           if(board[i][m-1]=='O') dfs(board,i,m-1);
        }

       for(int j=0;j<m;j++)  //first row traverse
        {
           if(board[n-1][j]=='O') dfs(board,n-1,j);
        }


        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]=='$') board[i][j]='O';
                else if(board[i][j]=='O') board[i][j]='X';
            }
        }
    }
};