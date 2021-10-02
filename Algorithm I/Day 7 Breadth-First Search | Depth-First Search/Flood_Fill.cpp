class Solution {
public:
    vector<vector<int> > floodFill(vector<vector<int> >& image, int sr, int sc, int newColor)
    {
        if (image[sr][sc] == newColor)
            return image;
        int oldColor = image[sr][sc];
        DFS(image, sr, sc, oldColor, newColor);
        return image;
    }

    void DFS(vector<vector<int> >& image, int r, int c, int oldColor, int newColor)
    {
        int x[] = { 0, 1, 0, -1 };
        int y[] = { 1, 0, -1, 0 };

        image[r][c] = newColor;

        for (int i = 0; i < 4; i++) {
            int _x = r + x[i];
            int _y = c + y[i];
            if (check(image, _x, _y, image.size(), image[0].size(), oldColor)) {
                image[_x][_y] = newColor;
                DFS(image, _x, _y, oldColor, newColor);
            }
        }
        return;
    }

    bool check(vector<vector<int> >& image, int r, int c, int n, int m, int oldColor)
    {
        return r >= 0 && r < n && c >= 0 && c < m && image[r][c] == oldColor;
    }
};