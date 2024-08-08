class Solution {
public:
    bool isValid(int i,int j,int row,int col)
    {
        if(i<0 || i>=row || j<0 || j>=col) return false;
        return true;
    }
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
        vector<vector<int>>ans;
        ans.push_back({r,c});
        int len=1;
        int total=rows*cols;
        int cnt=1;

        while(cnt<total)
        {
            for(int i=1;i<=len && cnt<total;i++)
            {
                if(isValid(r,c+i,rows,cols))
                {
                ans.push_back({r,c+i});
                cnt++;

                }
            }
            c=c+len;

            for(int i=1;i<=len && cnt<total;i++)
            {
                if(isValid(r+i,c,rows,cols))
                {
                    ans.push_back({r+i,c});
                   cnt++;
                }
            }
            r=r+len;

            len++;
            for(int i=1;i<=len && cnt<total;i++)
            {
                if(isValid(r,c-i,rows,cols))
                {
                    ans.push_back({r,c-i});
                   cnt++;
                }
            }
            c=c-len;
            for(int i=1;i<=len && cnt<total;i++)
            {
                if(isValid(r-i,c,rows,cols))
                {
                    ans.push_back({r-i,c});
                    cnt++;
                }
            }
            r=r-len;
            len++;
        }

        return ans;

    }
};