class Solution {
public:
    int  solve(vector<vector<int>>&matrix,int row,int col)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        if(row==matrix.size()-1) return matrix[row][col];

        int sum=matrix[row][col];

        int minSum=INT_MAX;

        for(int nextCol=0;nextCol<m;nextCol++)
        {
            if(nextCol!=col)
            minSum=min(minSum,sum+solve(matrix,row+1,nextCol));
        }

        return minSum;   
    }

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

    //3.Tabluation:-
    int  solveTab(vector<vector<int>>&matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<vector<int>>dp(n,vector<int>(m+1,0));

        for(int j=0;j<m;j++)
        {
            dp[n-1][j]= matrix[n-1][j];
        }

        

        for(int row=n-2;row>=0;row--)
        {
            for(int col=m-1;col>=0;col--)
            {
                int sum=matrix[row][col];
                int minSum=INT_MAX;
                
                for(int nextCol=0;nextCol<m;nextCol++)
                {
                    if(nextCol!=col)
                    minSum=min(minSum,sum+dp[row+1][nextCol]);
                }

                dp[row][col]=minSum;
            }
        }
        int mini=INT_MAX;
        for(int j=0;j<m;j++)
        {
            mini=min(mini,dp[0][j]);
        }
        return mini; 
        
    }

    //4.Space
     int  space(vector<vector<int>>&matrix)
    {
        int n=matrix.size();
        int m=matrix[0].size();
        vector<int>curr(m+1,0);
        vector<int>next(m+1,0);
        for(int j=0;j<m;j++)
        {
            next[j]= matrix[n-1][j];
        }

        

        for(int row=n-2;row>=0;row--)
        {
            for(int col=m-1;col>=0;col--)
            {
                int sum=matrix[row][col];
                int minSum=INT_MAX;
                if(col-1>=0)
                minSum=min(minSum,sum+next[col-1]);

                minSum=min(minSum,sum+next[col]);

                if(col+1<m)
                minSum=min(minSum,sum+next[col+1]);

                curr[col]=minSum;
            }
            next=curr;
        }
        int mini=INT_MAX;
        for(int j=0;j<m;j++)
        {
            mini=min(mini,next[j]);
        }
        return mini; 
        
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        // int n=matrix.size();
        // int m=matrix[0].size();
        // int mini=INT_MAX;
        // vector<vector<int>>dp(n,vector<int>(m,-1));
        // for(int j=0;j<m;j++)
        // {
        //     mini=min(mini,solveMem(matrix,0,j,dp));
        // }
        // return mini;

        //3.Tabulation
        return solveTab(matrix);


        //4.space
        // return space(matrix);
    }
};