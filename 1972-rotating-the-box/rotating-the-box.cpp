class Solution {
public:
    vector<vector<char>> rotateTheBox(vector<vector<char>>& box) {
        int m=box.size();
        int n=box[0].size();
        vector<vector<char>>ans(n,vector<char>(m));
        for(int i=m-1;i>=0;i--)
        {
            for(int j=n-1;j>=0;j--)
            {
                if(box[i][j]=='#')
                {
                    //move right till obstacles or boundary
                    int temp=j+1;
                    while(temp<n && box[i][temp]!='*' && box[i][temp]!='#')
                    {
                        temp++;
                    }
                    swap(box[i][j],box[i][temp-1]);
                }
            }
        }
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                cout<<box[i][j]<<" ";
            }
            cout<<endl;
        }
        //traverse
        
        for(int i=0;i<m;i++)
        {
            for(int j=0;j<n;j++)
            {
                ans[j][m - 1 - i] = box[i][j];
            }
        }
        return ans;
    }
};