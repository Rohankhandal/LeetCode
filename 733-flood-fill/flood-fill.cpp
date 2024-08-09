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

    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int startColor = image[sr][sc];
        if (startColor != color) {
            dfs(image, sr, sc, startColor, color);
        }
        return image;
    }
};
