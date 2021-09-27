class Solution {
public:
    int search(vector<int>& nums, int target) {
        int indx = lower_bound(nums.begin() , nums.end() , target) - nums.begin();
        return (indx < nums.size () && nums[indx] == target) ? indx : -1;
    }
};