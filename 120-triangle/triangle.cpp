// Bottom-Up
class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        int height = triangle.size();
        
        // Create a dp table with all elements initialized to 0
        vector<vector<int>> dp(height + 1, vector<int>(height + 1, 0));
        
        // Initialize the last row of dp with the last row of the triangle
        for (int i = 0; i < height; i++) {
            dp[height - 1][i] = triangle[height - 1][i];
        }
        
        // Fill the dp table from the second last row to the top
        for (int i = height - 2; i >= 0; i--) {
            int m = triangle[i].size();
            for (int j = 0; j < m; j++) {
                dp[i][j] = triangle[i][j] + min(dp[i + 1][j], dp[i + 1][j + 1]);
            }
        }
        
        // The result is stored at the top of the triangle in dp[0][0]
        return dp[0][0];
    }
};
