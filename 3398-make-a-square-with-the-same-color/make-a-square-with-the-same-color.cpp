class Solution {
public:
    bool canMakeSquare(vector<vector<char>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        for(int i=1;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                int Bcount=0;
                int Wcount=0;
                if(matrix[i][j]=='B') Bcount++;
                if(matrix[i][j]=='W') Wcount++;
                if(i-1>=0)
                {
                    if(matrix[i-1][j]=='B') Bcount++;
                    if(matrix[i-1][j]=='W') Wcount++;
                }
                if(i-1>=0 && j+1<m)
                {
                    if(matrix[i-1][j+1]=='B') Bcount++;
                    if(matrix[i-1][j+1]=='W') Wcount++;
                }
                if(j+1<m)
                {
                    if(matrix[i][j+1]=='B') Bcount++;
                    if(matrix[i][j+1]=='W') Wcount++;
                }
                if(Bcount>=3 || Wcount>=3) return true;
                Bcount=0;
                Wcount=0;
                if(matrix[i][j]=='B') Bcount++;
                if(matrix[i][j]=='W') Wcount++;
                if(i+1<n)
                {
                    if(matrix[i+1][j]=='B') Bcount++;
                    if(matrix[i+1][j]=='W') Wcount++;
                }
                if( j+1<m)
                {
                    if(matrix[i][j+1]=='B') Bcount++;
                    if(matrix[i][j+1]=='W') Wcount++;
                }
                if(i+1<n && j+1<m)
                {
                    if(matrix[i+1][j+1]=='B') Bcount++;
                    if(matrix[i+1][j+1]=='W') Wcount++;
                }
                if(Bcount>=3 || Wcount>=3) return true;
            }
        }
        return false;
    }
};