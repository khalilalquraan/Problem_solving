class Solution {
public:
    vector<int> grayCode(int n)
    {
        bitset<32> bits;
        vector<int> ans;
        backtrack(bits, ans, n);
        return ans;
    }

    void backtrack(bitset<32>& bits, vector<int>& ans, int n)
    {
        if (n == 0) {
            ans.push_back(bits.to_ulong());
            return;
        }
        backtrack(bits, ans, n - 1);
        bits.flip(n - 1);
        backtrack(bits, ans, n - 1);
    }
};