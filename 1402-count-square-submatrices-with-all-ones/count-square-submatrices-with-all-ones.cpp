class Solution {
public:
    int countSquares(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m,0));

        //insert first row of matrix into dp table
        for(int j=0;j<m;j++)
        {
            dp[0][j]=matrix[0][j];
        }
        //insert first column of matrix into dp table
        for(int i=0;i<n;i++)
        {
            dp[i][0]=matrix[i][0];
        }
        for(int i=1;i<n;i++)
        {
            for(int j=1;j<m;j++)
            {
                if(matrix[i][j]==1)
                {
                    dp[i][j]=1+min({dp[i-1][j],dp[i][j-1],dp[i-1][j-1]});
                }
                else dp[i][j]=0;
            }
        }

        int cntSqu=0;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                cntSqu+=dp[i][j];
            }
        }
        return cntSqu;
    }
};