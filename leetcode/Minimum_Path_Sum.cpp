class Solution {
public:
    int minPathSum(vector<vector<int> >& grid)
    {
        int dp[201][201];
        memset(dp, -1, sizeof(dp));
        return findMinPathSum(0, 0, dp, grid);
    }

    int findMinPathSum(int i, int j, int dp[201][201], vector<vector<int> >& grid)
    {
        if (i == grid.size() || j == grid[0].size())
            return 1e8;
        if (i == grid.size() - 1 && j == grid[0].size() - 1)
            return grid[i][j];

        if (dp[i][j] != -1)
            return dp[i][j];

        int ans = grid[i][j] + min(findMinPathSum(i + 1, j, dp, grid), findMinPathSum(i, j + 1, dp, grid));

        return dp[i][j] = ans;
    }
};