class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j,int m,int n)
    {
        if(grid[i][j]!=1 && i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        // if(dp[i][j]!=-1) return dp[i][j];

        int val1=0;
        if(i+1<m && grid[i+1][j]!=1)
            val1=solve(grid,i+1,j,m,n); //down

        int val2=0;
        if(j+1<n && grid[i][j+1]!=1)
            val2=solve(grid,i,j+1,m,n); //right

        return val1+val2;
    }

    int solveMem(vector<vector<int>>& grid,int i,int j,int m,int n, vector<vector<int>>&dp)
    {
        if( i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];

        int val1=0;
        if(i+1<m && grid[i+1][j]!=1)
            val1=solveMem(grid,i+1,j,m,n,dp); //down

        int val2=0;
        if(j+1<n && grid[i][j+1]!=1)
            val2=solveMem(grid,i,j+1,m,n,dp); //right

        return dp[i][j]=val1+val2;
    }

    //3.Tabluation
    int solveTab(vector<vector<int>>& grid, int m, int n) {
    vector<vector<long long>> dp(m + 1, vector<long long>(n + 1, 0));
    dp[m - 1][n - 1] = 1;

    for (int i = m - 1; i >= 0; i--) {
        for (int j = n - 1; j >= 0; j--) {
            if (i == m - 1 && j == n - 1) continue;

            long long val1 = 0;
            if (i + 1 < m && grid[i + 1][j] != 1)
                val1 = dp[i + 1][j]; // down

            long long val2 = 0;
            if (j + 1 < n && grid[i][j + 1] != 1)
                val2 = dp[i][j + 1]; // right

            dp[i][j] = val1 + val2;
        }
    }

    return dp[0][0];
}
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int m=obstacleGrid.size();
        int n=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1) return 0;  //IMP BASE CASE
        // return solve(obstacleGrid,0,0,m,n);

        // vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return solveMem(obstacleGrid,0,0,m,n,dp);

        return solveTab(obstacleGrid,m,n);



    }
};