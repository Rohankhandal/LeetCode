class Solution {
public:
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int n=matrix.size();
        vector<vector<int>>dp(n,vector<int>(n,INT_MAX));
        for(int j=0;j<n;j++){
            dp[0][j]=matrix[0][j];
        }

        for(int i=1;i<n;i++){
            for(int j=0;j<n;j++){
                if(j-1>=0)
                dp[i][j]=min(dp[i][j],matrix[i][j]+dp[i-1][j-1]);

                dp[i][j]=min(dp[i][j],matrix[i][j]+dp[i-1][j]);

                if(j+1<n)
                dp[i][j]=min(dp[i][j],matrix[i][j]+dp[i-1][j+1]);
            }
        }

        int ans=INT_MAX;
        for(int j=0;j<n;j++)
        {
            ans=min(dp[n-1][j],ans);
        }
        return ans;
    }
};