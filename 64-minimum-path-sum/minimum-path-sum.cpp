class Solution {
public:
    long long solve(vector<vector<int>>& grid,int m,int n,int i,int j)
    {
        if(i==m-1 && j==n-1) return grid[m-1][n-1];

        if(i>=m || j>=n) return INT_MAX;

        long long val1=grid[i][j]+solve(grid,m,n,i+1,j);
        long long val2=grid[i][j]+solve(grid,m,n,i,j+1);

        return min(val1,val2);
    }
    long long solveMem(vector<vector<int>>& grid,int m,int n,int i,int j, vector<vector<int>>&dp)
    {
        if(i==m-1 && j==n-1) return grid[m-1][n-1];

        if(i>=m || j>=n) return INT_MAX;

        if(dp[i][j]!=-1 ) return dp[i][j];
        long long val1=grid[i][j]+solveMem(grid,m,n,i+1,j,dp);
        long long val2=grid[i][j]+solveMem(grid,m,n,i,j+1,dp);

        return dp[i][j]=min(val1,val2);
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m=grid.size();
        int n=grid[0].size();
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        // return solve(grid,m,n,0,0);


        return solveMem(grid,m,n,0,0,dp);
    }
};