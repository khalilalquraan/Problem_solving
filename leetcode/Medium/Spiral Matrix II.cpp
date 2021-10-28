/*
    Problem Url : https://leetcode.com/problems/spiral-matrix-ii/
    Date : 2021-07-16
*/
class Solution {
public:
    vector<vector<int>> generateMatrix(int n) {
        vector<vector<int>>ans(n);
        for(auto & i:ans)i = vector<int>(n);
        int c1=0,c2=1;
        DFS(ans,0,0,n,n,c1,c2);
        return ans;
    }
    
    int vis[1000][1000];
    int x[4] = { 0, 1, 0, -1 };
    int y[4] = { 1, 0, -1, 0 };
    void DFS(vector<vector<int> > & matrix, int _x, int _y, int m, int n, int& cou,int& i)
    {
        if (_x == m || _y == n || _x < 0 || _y < 0 || vis[_x][_y]) {
            cou++;
            return;
        }

        vis[_x][_y] = true;
        matrix[_x][_y] = i++;
        DFS(matrix, _x + x[cou % 4], _y + y[cou % 4], m, n, cou,i);
        DFS(matrix, _x + x[cou % 4], _y + y[cou % 4], m, n, cou,i);
        return;
    }
};