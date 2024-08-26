class Solution {
public:
    int solve(vector<vector<int>>& grid,int i,int j)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i==n-1 && j==m-1) return 1;
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==1) return 0;

        //down 
        int down=solve(grid,i+1,j);

        //right
        int right=solve(grid,i,j+1);

        return right+down;

    }

//2.Memoziation
    int solveMem(vector<vector<int>>& grid,int i,int j,vector<vector<int>>&dp)
    {
        int n=grid.size();
        int m=grid[0].size();
        if(i==n-1 && j==m-1) return 1;
        if(i<0 || i>=n || j<0 || j>=m || grid[i][j]==1) return 0;

        if(dp[i][j]!=-1) return dp[i][j];
        //down 
        int down=solveMem(grid,i+1,j,dp);

        //right
        int right=solveMem(grid,i,j+1,dp);

        return dp[i][j]=right+down;

    }


    //3.Tabluation
    int solveTab(vector<vector<int>>& grid)
    {
        int n=grid.size();
        int m=grid[0].size();
        vector<vector<long long  >>dp(n+1,vector<long long>(m+1,0));
        dp[n-1][m-1]=1;
        
        for(int i=n-1;i>=0;i--)
        {
            for(int j=m-1;j>=0;j--)
            {
                if(i==n-1 && j==m-1) continue;

                if(grid[i][j]==1) continue;
                //down 
                long long  down=dp[i+1][j];

                //right
                long long   right=dp[i][j+1];

                dp[i][j]=right+down;
            }
        }

        return dp[0][0];

    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        int n=obstacleGrid.size();
        int m=obstacleGrid[0].size();
        if(obstacleGrid[0][0]==1 ||obstacleGrid[n-1][m-1]==1) return 0;

        // return solve(obstacleGrid,0,0);


        //2.Memoization
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // return solveMem(obstacleGrid,0,0,dp);


        //3.Tabluation
        return solveTab(obstacleGrid);
    }
};