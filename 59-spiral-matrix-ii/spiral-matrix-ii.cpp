class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        
        vector<vector<int>>ans(n,vector<int>(n));
        int rowStart=0;
        int rowEnd=n-1;
        int colStart=0;
        int colEnd=n-1;
        int totalEle=1;
        while(totalEle<=n*n)
        {
            for(int i=colStart;i<=colEnd&&totalEle<=n*n;i++)
            {
                ans[rowStart][i]=totalEle;
                totalEle++;
            }
            rowStart++;
            for(int i=rowStart;i<=rowEnd&&totalEle<=n*n;i++)
            {
                ans[i][colEnd]=totalEle;
                totalEle++;
            }
            colEnd--;
            for(int i=colEnd;i>=colStart&&totalEle<=n*n;i--)
            {
                ans[rowEnd][i]=totalEle;
                totalEle++;
            }
            rowEnd--;
            for(int i=rowEnd;i>=rowStart&&totalEle<=n*n;i--)
            {
                ans[i][colStart]=totalEle;
                totalEle++;
            }
            colStart++;
        }
        return ans;
    }
};
