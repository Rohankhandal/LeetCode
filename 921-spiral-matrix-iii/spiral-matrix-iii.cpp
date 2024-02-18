class Solution {
public:
bool isValid(int i, int j,int n, int m)
{
    return !(i<0||j<0||i>=n||j>=m);
}
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
        vector<vector<int>>ans{{r,c}};  //first insert current position
        int x=r;
        int y=c;
        int total_ele=rows*cols;
        int count=0;
        int len=1;
       
        while(ans.size()<total_ele)
        {
            for(int i=1;i<=len;i++)
            {
                if(isValid(x,y+i,rows,cols))
                {
                    ans.push_back({x,y+i});
                }
            }
            y+=len;  //going right;

            for(int i=1;i<=len;i++)
            {
                if(isValid(x+i,y,rows,cols))
                {
                    ans.push_back({x+i,y});
                }
            }

            x+=len;  //going down;
            len++; //increasing length after down in over;


            for(int i=1;i<=len;i++)
            {
                if(isValid(x,y-i,rows,cols))
                {
                    ans.push_back({x,y-i});
                }
            }

            y-=len;  //going left;

               
            for(int i=1;i<=len;i++)
            {
                if(isValid(x-i,y,rows,cols))
                {
                    ans.push_back({x-i,y});
                }
            }

            x-=len;  //going up
            len++; 

        }
        return ans;
    }
};