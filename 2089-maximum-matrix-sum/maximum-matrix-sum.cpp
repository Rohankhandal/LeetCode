class Solution {
public:
    long long maxMatrixSum(vector<vector<int>>& matrix) {
       
        int n=matrix.size();
        int m=matrix[0].size();
        long long negCnt=0;
        long long totalSum=0;
       long long zeroCnt=0;  //if there is any zero element , then all minus sign go to zero

        long long minEle=LLONG_MAX;
        for(int i=0;i<n;i++)
        {
            for(int j=0;j<m;j++)
            {
                if(matrix[i][j]<0)
                {
                    negCnt++;
                }
                minEle = min(minEle, (long long)abs(matrix[i][j]));

                if(matrix[i][j]==0) zeroCnt++;
                totalSum+=abs(matrix[i][j]);
            }
        }
        if(negCnt%2==0 || zeroCnt>0 ) return totalSum;

        totalSum-=2*abs(minEle);

        return totalSum;
    }
};