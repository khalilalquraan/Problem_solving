/*
    Problem Url : https://leetcode.com/problems/spiral-matrix/
    Date : 2021-07-16
*/
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int> >& matrix)
    {
        vector<int> ans;
        int cou = 0;
        DFS(ans, matrix, 0, 0, matrix.size(), matrix[0].size(), cou);
        return ans;
    }
    int vis[1000][1000];
    int x[4] = { 0, 1, 0, -1 };
    int y[4] = { 1, 0, -1, 0 };
    void DFS(vector<int>& ans, vector<vector<int> > matrix, int _x, int _y, int m, int n, int& cou)
    {
        if (_x == m || _y == n || _x < 0 || _y < 0 || vis[_x][_y]) {
            cou++;
            return;
        }

        vis[_x][_y] = true;
        ans.push_back(matrix[_x][_y]);
        DFS(ans, matrix, _x + x[cou % 4], _y + y[cou % 4], m, n, cou);
        DFS(ans, matrix, _x + x[cou % 4], _y + y[cou % 4], m, n, cou);
        return;
    }
};