class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<pair<int,int>>v;
        int m=matrix.size();
        int n=matrix[0].size();
        for(int i=0;i<m;i++)
        {
            
            for(int j=0;j<n;j++)
            {
                if(matrix[i][j]==0)
                {
                    v.push_back({i,j});
                }
            }
        }
        if(v.size()==0) return ;
        else
        {
            for(auto &it:v)
            {
                int i=it.first;
                int j=it.second;
                int row=0;
                int col=0;
                while(col<n)
                {
                    matrix[i][col++]=0;
                }
                while(row<m)
                {
                    matrix[row++][j]=0;
                }
            }
        }
    }
};