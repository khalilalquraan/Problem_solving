/*
 Problem Url : https://leetcode.com/problems/3sum-closest
 Date : 30-06-2021
*/
class Solution {
public:
    int threeSumClosest(vector<int>& nums, int target)
    {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int ans = 1e9;
        for (int i = 0; i < n; i++) {
            for (int j = i + 1; j < n; j++) {
                int comp = target - nums[i] - nums[j];
                int hi = upper_bound(nums.begin() + j + 1, nums.end(), comp) - nums.begin();
                int lo = hi - 1;
                if (hi < n && abs(comp - nums[hi]) < abs(ans)) {
                    ans = comp - nums[hi];
                }
                if (lo > j && abs(comp - nums[lo]) < abs(ans)) {
                    ans = comp - nums[lo];
                }
            }
        }
        return target - ans;
    }
};