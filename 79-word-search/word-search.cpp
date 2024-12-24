class Solution {
public:
        vector<vector<int>>dir{{-1,0},{0,1},{1,0},{0,-1}};
    bool isSame(vector<vector<char>>& board, string &word,int i,int j,int idx)
    {
        int n=board.size();
        int m=board[0].size();

        if(idx>=word.size()) return true;
        
        if(i<0 || i>=n || j<0 || j>=m || board[i][j]!=word[idx]) return false;

        // Temporarily mark the cell as visited
        char temp = board[i][j];
        board[i][j] = '#';

        for(auto &d:dir)
        {
            int newI=i+d[0];
            int newJ=j+d[1];

            if(isSame(board,word,newI,newJ,idx+1))
            {
                return true;
            }
            
        }
        // Backtrack by unmarking the cell
        board[i][j] = temp;
        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int n=board.size();
        int m=board[0].size();

        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(board[i][j]==word[0] && isSame(board,word,i,j,0))
                {
                    return true;
                }
            }
        }
        return false;
    }
};