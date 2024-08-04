class Solution {
public:
    int check(vector<int>&row,int size)
    {
        int flip=0;
        int l=0,r=size-1;
        while(l<r)
        {
            if(row[l]!=row[r])
            {
                flip++;
            }
            l++;
            r--;
        }
        return flip;
    }
    int minFlips(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();
        int rowFlip=0;
        for(auto &row:grid)
        {
            rowFlip+=check(row,m);
        }

    int colFlip=0;
        for(int j=0;j<m;j++)
        {
            vector<int>col(n,0);
            int k=0;
            for(int i=0;i<n;i++)
            {
                col[k]=grid[i][j];
                // cout<<k<<endl;
                k++;
            }

            colFlip+=check(col,n);

        }
        return min(rowFlip,colFlip);
    }
};