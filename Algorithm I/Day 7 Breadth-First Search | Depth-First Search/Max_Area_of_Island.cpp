class Solution {
public:
    int maxAreaOfIsland(vector<vector<int> >& grid)
    {
        bool vis[51][51];
        memset(vis, 0, sizeof(vis));
        int ans = 0;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (!vis[i][j] && grid[i][j]) {
                    ans = max(ans, findAreaOfLand(grid, i, j, vis));
                }
            }
        }
        return ans;
    }

    int findAreaOfLand(vector<vector<int> >& grid, int r, int c, bool(&vis)[51][51])
    {
        int x[] = { 0, 1, 0, -1 };
        int y[] = { 1, 0, -1, 0 };

        vis[r][c] = true;
        int ans = 1;
        for (int i = 0; i < 4; i++) {
            int _x = r + x[i];
            int _y = c + y[i];

            if (isVaild(grid, _x, _y, grid.size(), grid[0].size(), vis)) {
                ans += findAreaOfLand(grid, _x, _y, vis);
            }
        }
        return ans;
    }

    bool isVaild(vector<vector<int> >& grid, int r, int c, int n, int m, bool(&vis)[51][51])
    {
        return r >= 0 && r < n && c >= 0 && c < m && !vis[r][c] && grid[r][c];
    }
};