/*
    Problem Url : https://leetcode.com/problems/combination-sum/ 
    Date : 2021-07-09
*/
class Solution {
public:
    vector<vector<int> > combinationSum(vector<int>& candidates, int target)
    {
        vector<vector<int> > ans;
        generateSolution(0, ans, vector<int>(), candidates, target);
        return ans;
    }

    void generateSolution(int indx, vector<vector<int> >& ans, vector<int> combination, vector<int> candidates, int target)
    {
        if (target < 0 || indx == candidates.size())
            return;
        if (target == 0) {
            ans.push_back(combination);
            return;
        }

        combination.push_back(candidates[indx]);
        generateSolution(indx, ans, combination, candidates, target - candidates[indx]);
        combination.pop_back();

        generateSolution(indx + 1, ans, combination, candidates, target);

        return;
    }
};