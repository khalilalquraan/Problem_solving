class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums)
    {
        vector<int> ans(nums.size());
        int start = 0, end = nums.size() - 1;
        for (int i = nums.size() - 1; i >= 0; i--) {
            if (abs(nums[start]) > abs(nums[end])) {
                ans[i] = nums[start] * nums[start];
                start++;
            }
            else {
                ans[i] = nums[end] * nums[end];
                end--;
            }
        }
        return ans;
    }
};