class Solution {
public:
    vector<vector<int>>dir{{1,0},{-1,0},{0,1},{0,-1}};
    bool find(vector<vector<char>>&board,int i,int j,string &word,int idx)
    {
        if(idx==word.length()) return true;

        if(i<0 || j<0 || i>=board.size() || j>=board[0].size() || board[i][j]=='$')
        {
            return false;
        }

        if(board[i][j]!=word[idx])
        {
            return false;
        }
        //store current char in temp
        char temp=board[i][j];
        //visited the current char
        board[i][j]='$';

        //now word are match board[i][j]==word[idx]
        for(auto &it:dir)
        {
            int new_x=i+it[0];
            int new_y=j+it[1];

            if(find(board,new_x,new_y,word,idx+1))
            {
                return true;
            }
        }
        //backtracking
        board[i][j]=temp;

        return false;
    }
    bool exist(vector<vector<char>>& board, string word) {
        int m=board.size();
        int n=board[0].size();
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                if(board[i][j]==word[0] && find(board,i,j,word,0)){
                    return true;
                }
            }
        }
        return false;
    }
};