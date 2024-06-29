class Solution {
public:
    int solveMem(int i,int j,int m,int n,vector<vector<int>>&dp)
    {
        if(i==m-1 && j==n-1) return 1;
        if(i>=m || j>=n) return 0;
        if(dp[i][j]!=-1) return dp[i][j];
        int val1=solveMem(i+1,j,m,n,dp); //down
        int val2=solveMem(i,j+1,m,n,dp); //right

        return dp[i][j]=val1+val2;
    }
    int uniquePaths(int m, int n) {
        vector<vector<int>>dp(m+1,vector<int>(n+1,-1));
        return solveMem(0,0,m,n,dp);
    }
};