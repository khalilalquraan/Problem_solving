class Solution {
public:
    bool searchMatrix(vector<vector<int> >& matrix, int target)
    {
        int row = -1;
        for (int i = 0; i < matrix.size(); i++) {
            if (matrix[i][0] <= target)
                row = i;
        }

        if (row == -1)
            return false;

        int indx = lower_bound(matrix[row].begin(), matrix[row].end(), target) - matrix[row].begin();
        return (indx < matrix[0].size() && matrix[row][indx] == target);
    }
};