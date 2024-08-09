class Solution {
public:
    void dfs(vector<vector<int>>& image, int i, int j, int startColor, int color) {
        int n = image.size();
        int m = image[0].size();
        if (i < 0 || j < 0 || i >= n || j >= m || image[i][j] != startColor) return;

        image[i][j] = color;

        vector<vector<int>> dir{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        for (auto& d : dir) {
            int _x = d[0] + i;
            int _y = d[1] + j;
            dfs(image, _x, _y, startColor, color);
        }
    }


    void bfs(vector<vector<int>>& image, int i, int j, int startColor, int color) {

        image[i][j]=color;
        int n = image.size();
        int m = image[0].size();

        queue<pair<int,int>>q;
        q.push({i,j});

        vector<vector<int>> dir{{-1, 0}, {0, -1}, {1, 0}, {0, 1}};

        while(!q.empty())
        {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(auto &d:dir)
            {
                int _x = d[0] + x;
                int _y = d[1] + y;
                 if (_x < 0 || _y < 0 || _x >= n || _y >= m || image[_x][_y] != startColor) continue;

                image[_x][_y]=color;
                q.push({_x,_y});
            }
        }
       
    }
    
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        if (startColor != color) {
            bfs(image, sr, sc, startColor, color);
        }
        return image;
    }
};
