class Solution {
public:
    int orangesRotting(vector<vector<int> >& grid)
    {
        int vis[11][11];
        memset(vis, false, sizeof(vis));
        queue<pair<int, int> > q;
        int level = 0;
        bool foundOne = false;
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] == 2) {
                    q.push({ i, j });
                    vis[i][j] = true;
                }
                if (grid[i][j] == 1)
                    foundOne = true;
            }
        }
        int x[] = { 0, 1, 0, -1 };
        int y[] = { 1, 0, -1, 0 };
        int level_items = q.size();
        if (!foundOne)
            return 0;
        while (!q.empty()) {
            if (level_items == 0) {
                level++;
                level_items = q.size();
            }
            pair<int, int> front = q.front();
            q.pop();
            level_items--;
            vis[front.first][front.second] = true;
            for (int i = 0; i < 4; i++) {
                int _x = front.first + x[i];
                int _y = front.second + y[i];
                if (isVaild(_x, _y, vis, grid)) {
                    q.push({ _x, _y });
                    vis[_x][_y] = true;
                }
            }
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                if (grid[i][j] != 0 && !vis[i][j])
                    return -1;
            }
        }
        return level;
    }
    bool isVaild(int r, int c, int vis[11][11], vector<vector<int> >& grid)
    {
        return r >= 0 && r < grid.size() && c >= 0 && c < grid[0].size() && !vis[r][c] && grid[r][c] != 0;
    }
};