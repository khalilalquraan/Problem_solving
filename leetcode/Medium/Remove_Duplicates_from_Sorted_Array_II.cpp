class Solution {
public:
    int removeDuplicates(vector<int>& nums)
    {
        int i = 1, cur = 1, count = 1;

        while (i < nums.size()) {

            if (nums[i] == nums[i - 1])
                count++;
            else
                count = 1;
            nums[cur] = nums[i];
            if (count <= 2)
                cur++;
            i++;
        }

        return cur;
    }
};
