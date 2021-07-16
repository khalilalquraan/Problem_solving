/*
    Problem Url : https://leetcode.com/problems/permutations-ii/
    Date : 2021-07-15
*/
class Solution {
public:
    vector<vector<int> > permuteUnique(vector<int>& nums)
    {
        vector<vector<int> > ans;
        sort(nums.begin(), nums.end());
        calcPermute(0, nums, ans, vector<int>());
        return ans;
    }

    void calcPermute(int indx, vector<int> nums, vector<vector<int> >& ans, vector<int> perumte)
    {
        if (indx == nums.size()) {
            ans.push_back(perumte);
            return;
        }

        map<int, bool> vis;
        for (int i = 0; i < nums.size(); i++) {

            if (nums[i] == -100 || vis[nums[i]])
                continue;
            vis[nums[i]] = true;
            int tmp = nums[i];
            nums[i] = -100;
            perumte.push_back(tmp);
            calcPermute(indx + 1, nums, ans, perumte);
            perumte.pop_back();
            nums[i] = tmp;
        }

        return;
    }
};