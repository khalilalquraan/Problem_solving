/*
    Problem Url : https://leetcode.com/problems/jump-game-ii/
    Date : 13-07-2021
*/
class Solution {
public:
    int jump(vector<int>& nums)
    {
        int jum = 0, curEnd = 0, curFather = 0, n = nums.size();
        for (int i = 0; i < n - 1; i++) {
            curFather = max(curFather, nums[i] + i);
            if (i == curEnd) {
                jum++;
                curEnd = curFather;
            }
        }
        return jum;
    }
};