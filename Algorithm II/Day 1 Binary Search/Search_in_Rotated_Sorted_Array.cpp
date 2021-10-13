class Solution {
public:
    int search(vector<int>& nums, int target)
    {
        int pivot = findPivot(nums);
        int indx1 = lower_bound(nums.begin(), nums.begin() + pivot + 1, target) - nums.begin();
        int indx2 = lower_bound(nums.begin() + pivot + 1, nums.end(), target) - nums.begin();
        if (indx1 < nums.size() && nums[indx1] == target)
            return indx1;
        return (indx2 < nums.size() && nums[indx2] == target) ? indx2 : -1;
    }

    int findPivot(vector<int>& nums)
    {
        int l = 0, r = nums.size() - 1;
        int pivot = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (nums[mid] > nums.back()) {
                l = mid + 1;
                pivot = mid;
            }
            else {
                r = mid - 1;
            }
        }

        return pivot;
    }
};