class Solution {
public:
    int solve(vector<vector<int>>&triangle,int i,int j)
    {
        int n=triangle.size();
        if(i>=n) return 0;
        int m=triangle[i].size();
        if(j>=m) return 0;

        
        int currIndex=triangle[i][j]+solve(triangle,i+1,j);

        int nextIndex=triangle[i][j]+solve(triangle,i+1,j+1);
       
        return min(currIndex,nextIndex);
    }
    int solveMem(vector<vector<int>>&triangle,int i,int j, vector<vector<int>>&dp)
    {
        int n=triangle.size();
        if(i>=n) return 0;
        int m=triangle[i].size();
        if(j>=m) return 0;

        if(dp[i][j]!=-1) return dp[i][j];

        int currIndex=triangle[i][j]+solveMem(triangle,i+1,j,dp);

        int nextIndex=triangle[i][j]+solveMem(triangle,i+1,j+1,dp);
       
        return dp[i][j]=min(currIndex,nextIndex);
    }

    //3.Tabluation
    int solveTab(vector<vector<int>>&triangle)
    {
        int n=triangle.size();
         vector<vector<int>>dp(n+1,vector<int>(n+1,0));

        for(int i=n-1;i>=0;i--)
        {
            int m=triangle[i].size();
            for(int j=m-1;j>=0;j--){

                int currIndex=triangle[i][j]+dp[i+1][j];

                int nextIndex=triangle[i][j]+dp[i+1][j+1];
            
                dp[i][j]=min(currIndex,nextIndex);
            }
        }
        return dp[0][0];

        
    }
    int minimumTotal(vector<vector<int>>& triangle) {
    //    return  solve(triangle,0,0);

    //2.Memoziation
        // int n=triangle.size();
        // vector<vector<int>>dp(n,vector<int>(n,-1));
        // return solveMem(triangle,0,0,dp);


    //3.Tabluation
        return solveTab(triangle);
    }
};