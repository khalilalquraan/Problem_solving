/*
    Problem Url : https://leetcode.com/problems/combination-sum-ii/
    Date : 10-07-2021
*/
class Solution {
public:
    vector<vector<int> > combinationSum2(vector<int>& candidates, int target)
    {
        vector<vector<int> > ans;
        sort(candidates.begin(), candidates.end());
        generateSolution(0, ans, vector<int>(), candidates, target, -1);
        return ans;
    }

    void generateSolution(int indx, vector<vector<int> >& ans, vector<int> combination, vector<int> candidates, int target, int lastPop)
    {
        if (target == 0) {
            ans.push_back(combination);
            return;
        }

        if (target < 0 || indx == candidates.size())
            return;

        if (candidates[indx] != lastPop) {
            combination.push_back(candidates[indx]);
            generateSolution(indx + 1, ans, combination, candidates, target - candidates[indx], lastPop);
            combination.pop_back();
        }

        generateSolution(indx + 1, ans, combination, candidates, target, candidates[indx]);
    }
};