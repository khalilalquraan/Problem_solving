class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target)
    {
        int start = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int end = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        vector<int> ans;
        if (start < nums.size() && nums[start] == target)
            ans.push_back(start);
        else
            return vector<int>({ -1, -1 });
        if (end > 0 && nums[end - 1] == target)
            ans.push_back(end - 1);
        else
            return vector<int>({ -1, -1 });
        return ans;
    }
};