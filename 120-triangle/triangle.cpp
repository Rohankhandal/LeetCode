// Bottom-Up
class Solution {
public:
    int solve(vector<vector<int>>& triangle,int n,int i,int j)
    {
        if(i>=n) return 0;
        
        int m=triangle[i].size();
        if(j>m) return 0;
        int ans=INT_MAX;
        
        ans=triangle[i][j]+min(solve(triangle,n,i+1,j),solve(triangle,n,i+1,j+1));
        
        return ans;
    }
    
    //2.Memoziation
    int solveMem(vector<vector<int>>& triangle,int n,int i,int j, vector<vector<int>>&dp)
    {
        if(i>=n) return 0;
        
        int m=triangle[i].size();
        if(j>m) return 0;
        
        if(dp[i][j]!=-1 ) return dp[i][j];
        int ans=INT_MAX;
        
        ans=triangle[i][j]+min(solveMem(triangle,n,i+1,j,dp),solveMem(triangle,n,i+1,j+1,dp));
        
        return dp[i][j]=ans;
    }
    
    //3.Tabluation
    int solveTab(vector<vector<int>>& triangle)
    {
       
        int n=triangle.size();
      
        vector<vector<int>>dp(n+1,vector<int>(n+1,0));
        
        
        int ans=INT_MAX;
        for(int i=n-1;i>=0;i--)
        {
            int m=triangle[i].size();
            for(int j=0;j<m;j++)
            {
                 ans=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
                 dp[i][j]=ans;
            }
           
        }
        
       
        
        return dp[0][0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n=triangle.size();
        vector<vector<int>>dp(n,vector<int>(n,-1));
        
        // return solve(triangle,n,0,0);
        
        
        // return solveMem(triangle,n,0,0,dp);
        
        
        return solveTab(triangle);
    }
};


// 
// Bottom-Up
// class Solution {
// public:
//     int minimumTotal(vector<vector<int>>& triangle) {
//         int height = triangle.size();
        
//         // Create a dp table with all elements initialized to 0
//         vector<vector<int>> dp(height + 1, vector<int>(height + 1, 0));
        
//         // Initialize the last row of dp with the last row of the triangle
//         for (int i = 0; i < height; i++) {
//             dp[height - 1][i] = triangle[height - 1][i];
//         }
        
//         // Fill the dp table from the second last row to the top
//         for (int i = height - 2; i >= 0; i--) {
//             int m = triangle[i].size();
//             for (int j = 0; j < m; j++) {
//                 dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
//             }
//         }
        
//         // The result is stored at the top of the triangle in dp[0][0]
//         return dp[0][0];
//     }
// };
