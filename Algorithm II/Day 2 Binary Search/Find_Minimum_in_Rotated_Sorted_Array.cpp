class Solution {
public:
    int findMin(vector<int>& nums)
    {
        int n = nums.size();
        int indx = (findPivot(nums) + 1) % n;
        return nums[indx];
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