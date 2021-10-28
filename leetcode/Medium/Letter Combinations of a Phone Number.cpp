/*
    Problem Url : https://leetcode.com/problems/letter-combinations-of-a-phone-number/
    Date : 2021-07-20
*/
class Solution {
public:
    vector<string> letterCombinations(string digits)
    {
        string mapChar[10] = { "", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz" };
        vector<string> ans;
        PossibleLetterCombinations(0, digits, "", ans, mapChar);
        return ans;
    }

    void PossibleLetterCombinations(int indx, string digits, string combination, vector<string>& ans, string mapChar[])
    {
        if (indx == digits.size()) {
            if (combination != "")
                ans.push_back(combination);
            return;
        }

        for (auto i : mapChar[digits[indx] - '0']) {
            PossibleLetterCombinations(indx + 1, digits, combination + i, ans, mapChar);
        }
        return;
    }
};