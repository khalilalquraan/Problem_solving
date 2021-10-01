class Solution {
public:
    int lengthOfLongestSubstring(string s)
    {
        map<char, int> m;
        int l = 0, r = 0;
        int ans = 0;
        while (l <= r && r < s.size()) {
            if (m[s[r]] == 0) {
                m[s[r]]++;
                r++;
                ans = max(ans, r - l);
            }
            else {
                m[s[l]]--;
                l++;
            }
        }
        return ans;
    }
};