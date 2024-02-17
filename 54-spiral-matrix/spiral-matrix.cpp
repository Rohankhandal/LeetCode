class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int m=matrix.size();
        int n=matrix[0].size();
        int rowStart=0;
        int rowEnd=m-1;
        int colStart=0;
        int colEnd=n-1;
        int totalEle=0;
        while(totalEle<m*n)
        {
            for(int i=colStart;i<=colEnd&&totalEle<m*n;i++)
            {
                ans.push_back(matrix[rowStart][i]);
                totalEle++;
            }
            rowStart++;
            for(int i=rowStart;i<=rowEnd&&totalEle<m*n;i++)
            {
                ans.push_back(matrix[i][colEnd]);
                totalEle++;
            }
            colEnd--;
            for(int i=colEnd;i>=colStart&&totalEle<m*n;i--)
            {
                ans.push_back(matrix[rowEnd][i]);
                totalEle++;
            }
            rowEnd--;
            for(int i=rowEnd;i>=rowStart&&totalEle<m*n;i--)
            {
                ans.push_back(matrix[i][colStart]);
                totalEle++;
            }
            colStart++;
        }
        return ans;
    }
};