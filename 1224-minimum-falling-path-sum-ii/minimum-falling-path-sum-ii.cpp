class Solution {
public:
     //2.Memoziation
    int  solveMem(vector<vector<int>>&matrix,int row,int col,vector<vector<int>>&dp)
    {
        int n=matrix.size();
        int m=matrix[0].size();

        if(row==matrix.size()-1) return matrix[row][col];

        if(dp[row][col]!=-1) return dp[row][col];

        int sum=matrix[row][col];

        int minSum=INT_MAX;

        for(int nextCol=0;nextCol<m;nextCol++)
        {
            if(nextCol!=col)
            minSum=min(minSum,sum+solveMem(matrix,row+1,nextCol,dp));
        }

        return dp[row][col]=minSum;
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        int m=matrix[0].size();
        int mini=INT_MAX;
        vector<vector<int>>dp(n,vector<int>(m,-1));
        for(int j=0;j<m;j++)
        {
            mini=min(mini,solveMem(matrix,0,j,dp));
        }
        return mini;

        //3.Tabulation
        // return solveTab(matrix);


        //4.space
        // return space(matrix);
    }
};