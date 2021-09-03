class Solution {
public:
    int calc(int i, int j, int dp[101][101], vector<vector<int> > soso)
    {
        if ((i >= soso.size() || j >= soso[0].size()) || soso[i][j] == 1)
            return 0;
        if (i == soso.size() - 1 && j == soso[0].size() - 1)
            return 1;

        if (dp[i][j] != -1)
            return dp[i][j];
        return dp[i][j] = calc(i + 1, j, dp, soso) + calc(i, j + 1, dp, soso);
    }
    int uniquePathsWithObstacles(vector<vector<int> >& obstacleGrid)
    {
        int dp[101][101];
        memset(dp, -1, sizeof(dp));
        return calc(0, 0, dp, obstacleGrid);
    }
};