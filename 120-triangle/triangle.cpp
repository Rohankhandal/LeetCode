class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height=triangle.size();
        vector<vector<int>>dp(height+1,vector<int>(height+1,0));
        for(int i=0;i<height;i++)
        {
            dp[height-1][i]=triangle[height-1][i];
        }
        for(int i=height-2;i>=0;i--)
        {
            int m=triangle[i].size();
            for(int j=0;j<m;j++)
            {
                dp[i][j]=triangle[i][j]+min(dp[i+1][j],dp[i+1][j+1]);
            }
        }
        return dp[0][0];
    }
};